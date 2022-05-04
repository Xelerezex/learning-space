#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>


// #define DEBUG_ON  1

#ifdef DEBUG_ON
    #include "test_runner.h"
#endif

bool isSubDomain(const std::string &subdomain, const std::string &domain)
{
    size_t i = 0;
    size_t j = 0;
    while (i < subdomain.size() && j < domain.size())
    {
        if (subdomain[i++] != domain[j++])
        {
            return false;
        }
    }
    if (subdomain.size() != domain.size())
    {
        return (j == domain.size() && subdomain[i] == '.') ||
               (i == subdomain.size() && domain[j] == '.');
    }
    return true;
}

std::vector<std::string> ReadBannedDomain(std::istream &is)
{
    size_t count;
    is >> count;
    std::vector<std::string> result;
    for (size_t i = 0; i < count; ++i)
    {
        std::string domain;
        is >> domain;
        reverse(begin(domain), end(domain));
        result.push_back(domain);

    }
    sort(begin(result), end(result));

    size_t insert_pos = 0;
    for (std::string& domain : result)
    {
        if (insert_pos == 0 || !isSubDomain(domain, result[insert_pos - 1]))
        {
            swap(result[insert_pos++], domain);
        }
    }
    result.resize(insert_pos);
    return result;
}


std::vector<std::string> ReadDomain(std::istream &is)
{
    size_t count;
    is >> count;
    std::vector<std::string> result;
    for (size_t i = 0; i < count; ++i)
    {
        std::string domain;
        is >> domain;
        reverse(begin(domain), end(domain));
        result.push_back(domain);
    }
    return result;
}



std::string CheckIfBanned(std::vector<std::string> &banned_, const std::string &domain)
{
    if (const auto it = upper_bound(begin(banned_), end(banned_), domain);
        it != begin(banned_) && isSubDomain(domain, *prev(it)))
    {
        return "Bad";
    }
    else
    {
        return "Good";
    }
}

#ifdef DEBUG_ON
    void SimpleTest()
    {
       std::string bdomains = "1\nya.ru\n";
       std::string sdomains = "5\nya.ru\nya.com\nm.ya.ru\nm.mail.ya.ru\nru\n";
       std::stringstream banned;
       std::stringstream search;
       banned << bdomains;
       search << sdomains;

       std::vector<std::string> banned_ = ReadBannedDomain(banned);
       std::vector<std::string> search_ = ReadDomain(search);

       std::vector<std::string> expected =
       {"Bad", "Good", "Bad", "Bad", "Good"};

       for (size_t i = 0; i < search_.size(); ++i)
       {
           ASSERT_EQUAL(CheckIfBanned(banned_, search_[i]), expected[i]);
       }
    }

    void TestSameLong()
    {
       std::string bdomains = "3\nya.ru\nm.ya.ru\nmoscow.spb.ru\n";
       std::string sdomains = "5\nm.maps.me\nm.ya.ru\nb.ya.ru\nm.ya\nya.ya\n";
       std::stringstream banned(bdomains);
       std::stringstream search(sdomains);
       std::vector<std::string> banned_ = ReadBannedDomain(banned);
       std::vector<std::string> search_ = ReadDomain(search);

       std::vector<std::string> expected =
       {"Good", "Bad", "Bad", "Good", "Good"};

       for (size_t i = 0; i < search_.size(); ++i)
       {
           ASSERT_EQUAL(CheckIfBanned(banned_, search_[i]), expected[i]);
       }
    }

    void TestSame()
    {
       std::string bdomains = "1\nm.spb.ru.com\n";
       std::string sdomains = "6\ncom\nru.com\nspb.ru.com\nm.spb.ru.com\ns.spb.ru.com\ns.m.spb.ru.com\n";
       std::stringstream banned(bdomains);
       std::stringstream search(sdomains);
       std::vector<std::string> banned_ = ReadBannedDomain(banned);
       std::vector<std::string> search_ = ReadDomain(search);

       std::vector<std::string> expected =
       {"Good", "Good", "Good", "Bad", "Good", "Bad"};

       for (size_t i = 0; i < search_.size(); ++i)
       {
           ASSERT_EQUAL(CheckIfBanned(banned_, search_[i]), expected[i]);
       }
    }

    void TestAllBanned()
    {
       std::string bdomains = "2\ncom\nya.ru\n";
       std::string sdomains = "7\ncom\nru.com\nspb.ru.com\nm.spb.ru.com\ns.spb.ru.com\ns.m.spb.ru.com\nspb.ya.ru\n";
       std::stringstream banned(bdomains);
       std::stringstream search(sdomains);
       std::vector<std::string> banned_ = ReadBannedDomain(banned);
       std::vector<std::string> search_ = ReadDomain(search);

       std::vector<std::string> expected =
       {"Bad", "Bad", "Bad", "Bad", "Bad", "Bad", "Bad"};

       for (size_t i = 0; i < search_.size(); ++i)
       {
           ASSERT_EQUAL(CheckIfBanned(banned_, search_[i]), expected[i]);
       }
    }

    void TestCheckSubDomains()
    {
       std::string bdomains = "8\nya.com\nspb.com\nm.com\nm.ya.com\nya.m.com\nya.ya.com\nyaya.com\nya.ru.com\n";
       std::string sdomains = "8\ncom\nru.com\nspb.ru.com\nm.spb.com\ns.spb.com\nspb.m.com\nspb.yaya.com\nmoscow.ya.ru\n";
       std::stringstream banned(bdomains);
       std::stringstream search(sdomains);
       std::vector<std::string> banned_ = ReadBannedDomain(banned);
       std::vector<std::string> search_ = ReadDomain(search);

       std::vector<std::string> expected =
       {"Good", "Good", "Good", "Bad", "Bad", "Bad", "Bad", "Good"};

       for (size_t i = 0; i < search_.size(); ++i)
       {
           ASSERT_EQUAL(CheckIfBanned(banned_, search_[i]), expected[i]);
       }
    }
#endif


int main()
{
    #ifdef DEBUG_ON
        TestRunner tr;
        RUN_TEST(tr, SimpleTest);
        RUN_TEST(tr, TestSameLong);
        RUN_TEST(tr, TestSame);
        RUN_TEST(tr, TestAllBanned);
        RUN_TEST(tr, TestCheckSubDomains);
    #endif

    std::vector<std::string> banned_domains = ReadBannedDomain(std::cin);
    std::vector<std::string> domains_to_check = ReadDomain(std::cin);

    for (const auto& domain : domains_to_check)
    {
        std::cout << CheckIfBanned(banned_domains, domain) << '\n';
    }

    return 0;
}
