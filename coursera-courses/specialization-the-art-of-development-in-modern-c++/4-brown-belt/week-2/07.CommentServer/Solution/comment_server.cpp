#include "test_runner.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <map>
#include <optional>
#include <unordered_set>

using namespace std;


pair<string, string> SplitBy(const string& what, const string& by)
{
    size_t pos = what.find(by);
    if (by.size() < what.size() && pos < what.size() - by.size())
    {
        return {what.substr(0, pos), what.substr(pos + by.size())};
    }
    else
    {
        return {what, {}};
    }
}

template<typename T>
T FromString(const string& s)
{
    T x;
    istringstream is(s);
    is >> x;
    return x;
}

pair<size_t, string> ParseIdAndContent(const string& body)
{
    auto [id_string, content] = SplitBy(body, " ");
    return {FromString<size_t>(id_string), content};
}

struct HttpRequest                                           // Input
{
    string method, path, body;
    map<string, string> get_params;
};

enum class HttpCode
{
    Ok       = 200,
    NotFound = 404,
    Found    = 302,
};

class HttpResponse                                           // Output
{
    private:
        HttpCode code;
        unordered_map<string, string> header;
        string content;

    public:
        explicit HttpResponse(int i_code, unordered_map<string, string> header_, string content_)
          : code{i_code},
            header(header_),
            content(content_)
            {}

        HttpResponse& SetCode(HttpCode a_code)
        {
            code = a_code;
            return *this;
        }
        HttpResponse& AddHeader(string name, string value)
        {
            header[name] = value;
            return *this;
        }
        HttpResponse& SetContent(string a_content)
        {
            content = a_content;
            return *this;
        }

        friend ostream& operator << (ostream& output, const HttpResponse& resp)
        {
            int _code = resp.code == HttpCode::Ok ? 200 :
                       (resp.code == HttpCode::Found ? 302 :
                       404);

            std::string comment = resp.code == HttpCode::Ok ? "OK" :
                                 (resp.code == HttpCode::Found ? "Found" :
                                 "NotFound");
            output << "HTTP/1.1 " << _code << " " << comment << '\n';

            for (const auto &[key, value] : resp.header)
            {
                output << key << ": " << value << '\n';
            }

            output << "Content-Length: " << resp.content.size() << '\n'
                   << resp.content << '\n';


            return output;
        }
};

struct LastCommentInfo
{
    size_t user_id, consecutive_count;
};

class CommentServer
{
    private:
        vector<vector<string>> comments_;
        std::optional<LastCommentInfo> last_comment;
        unordered_set<size_t> banned_users;

    public:
        HttpResponse ServeRequest(const HttpRequest& req)
        {
            //-----------------------------------------------------------------------------//
            if (req.method == "POST")
            {
                if (req.path == "/add_user")
                {
                    comments_.emplace_back();
                    std::string response = to_string(comments_.size() - 1);

                    return HttpResponse{200, {}, response};
                }
                else if (req.path == "/add_comment")
                {
                    auto [user_id, comment] = ParseIdAndContent(req.body);

                    if (!last_comment || last_comment->user_id != user_id)
                    {
                        last_comment = LastCommentInfo{user_id, 1};
                    }
                    else if (++last_comment->consecutive_count > 3)
                    {
                        banned_users.insert(user_id);
                    }

                    if (banned_users.count(user_id) == 0)
                    {
                        comments_[user_id].push_back(string(comment));

                        return HttpResponse{200, {}, {}};
                    }
                    else
                    {
                        return HttpResponse{302, {{"Location", "/captcha"}}, {}};
                    }
                }
                else if (req.path == "/checkcaptcha")
                {
                    if (auto [id, response] = ParseIdAndContent(req.body); response == "42")
                    {
                        banned_users.erase(id);
                        if (last_comment && last_comment->user_id == id)
                        {
                            last_comment.reset();
                        }

                        return HttpResponse{200, {}, {}};
                    }
                    else
                    {
                        return HttpResponse{302, {{"Location", "/captcha"}}, {}};
                    }
                }
                else
                {
                    return HttpResponse{404, {}, {}};
                }
            }
            //-----------------------------------------------------------------------------//
            else if (req.method == "GET")
            {
                if (req.path == "/user_comments")
                {
                    auto user_id = FromString<size_t>(req.get_params.at("user_id"));
                    string response;
                    for (const string& c : comments_[user_id])
                    {
                        response += c + '\n';
                    }

                    return HttpResponse{200, {}, response};
                }
                else if (req.path == "/captcha")
                {
                    return HttpResponse{200, {}, {"What's the answer for The Ultimate Question of Life, the Universe, and Everything?"}};
                }
                else
                {
                    return HttpResponse{404, {}, {}};
                }
            }
            //-----------------------------------------------------------------------------//
            else
            {
                return HttpResponse{404, {}, {}};
            }
        }
};


void Test(CommentServer& srv, const HttpRequest& request, const HttpResponse& expected)
{
    stringstream ss, ss_exp;
    ss << srv.ServeRequest(request);
    ss_exp << expected;

    ASSERT_EQUAL(ss.str(), ss_exp.str());
}

template <typename CommentServer>
void TestServer()
{
    CommentServer cs;

    const HttpResponse ok{200, {}, {}};
    const HttpResponse redirect_to_captcha{302, {{"Location", "/captcha"}}, {}};
    const HttpResponse not_found{404, {}, {}};

    Test(cs, {"POST", "/add_user", {}, {}}, HttpResponse{200, {}, "0"});
    Test(cs, {"POST", "/add_user", {}, {}}, HttpResponse{200, {}, "1"});
    Test(cs, {"POST", "/add_user", {}, {}}, HttpResponse{200, {}, "2"});
    Test(cs, {"POST", "/add_comment", "0 Hello", {}}, ok);
    Test(cs, {"POST", "/add_comment", "1 Hi", {}}, ok);
    Test(cs, {"POST", "/add_comment", "1 Buy my goods", {}}, ok);
    Test(cs, {"POST", "/add_comment", "1 Enlarge", {}}, ok);
    Test(cs, {"POST", "/add_comment", "1 Buy my goods", {}}, redirect_to_captcha);
    Test(cs, {"POST", "/add_comment", "0 What are you selling?", {}}, ok);
    Test(cs, {"POST", "/add_comment", "1 Buy my goods", {}}, redirect_to_captcha);

    Test(cs,
        {"GET", "/user_comments", "", {{"user_id", "0"}}},
        HttpResponse{200, {}, "Hello\nWhat are you selling?\n"}
    );
    Test(cs,
        {"GET", "/user_comments", "", {{"user_id", "1"}}},
        HttpResponse{200, {}, "Hi\nBuy my goods\nEnlarge\n"}
    );
    Test(cs,
        {"GET", "/captcha", "", {}},
        HttpResponse{200, {}, {"What's the answer for The Ultimate Question of Life, the Universe, and Everything?"}}
    );
    Test(cs,
        {"POST", "/checkcaptcha", "1 24", {}},
        redirect_to_captcha
    );
    // std::cerr << "OK!" <<std::endl;
    Test(cs,
        {"POST", "/checkcaptcha", "1 42", {}},
        ok
    );
    Test(cs,
        {"POST", "/add_comment", "1 Sorry! No spam any more", {}},
        ok
    );
    Test(cs,
        {"GET", "/user_comments", "", {{"user_id", "1"}}},
        HttpResponse{200, {}, "Hi\nBuy my goods\nEnlarge\nSorry! No spam any more\n"}
    );
    Test(cs, {"GET", "/user_commntes", "", {}}, not_found);
    Test(cs, {"POST", "/add_uesr", "", {}}, not_found);
    /**/
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestServer<CommentServer>);
}
