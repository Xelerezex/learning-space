#include "stats.h"

Stats::Stats() :
    Methods(
        {
            {"GET", 0},
            {"POST", 0},
            {"PUT", 0},
            {"DELETE", 0},
            {"UNKNOWN", 0}
        }
    ),
    Uris(
        {
            {"/", 0},
            {"/order", 0},
            {"/product", 0},
            {"/basket", 0},
            {"/help", 0},
            {"unknown", 0}
        }
    ){}

void Stats::AddMethod(string_view method) {
    if (method == "GET") {
        Methods[method] += 1;
    } else if (method == "POST") {
        Methods[method] += 1;
    } else if (method == "PUT") {
        Methods[method] += 1;
    } else if (method == "DELETE") {
        Methods[method] += 1;
    } else {
        Methods["UNKNOWN"] += 1;
    }
}

void Stats::AddUri(string_view uri) {
    if (uri == "/") {
        Uris[uri] += 1;
    } else if (uri == "/order") {
        Uris[uri] += 1;
    } else if (uri == "/product") {
        Uris[uri] += 1;
    } else if (uri == "/basket") {
        Uris[uri] += 1;
    } else if (uri == "/help") {
        Uris[uri] += 1;
    } else {
        Uris["unknown"] += 1;
    }
}

const map<string_view, int>& Stats::GetMethodStats() const {

    return Methods;
}

const map<string_view, int>& Stats::GetUriStats() const {

    return Uris;
}

HttpRequest ParseRequest(string_view line) {
    string str {""};
    HttpRequest output;

    line.remove_prefix(line.find_first_not_of(' '));

    output.method = line.substr(0, line.find('/'));
    auto end_method = output.method.size() - output.method.find(' ');
    output.method.remove_suffix(end_method);

    line.remove_prefix(output.method.size() - output.method.find(' '));

    output.uri = line.substr(0, line.find(' '));
    line.remove_prefix(line.find_first_of(' '));

    line.remove_prefix(line.find_first_not_of(' '));
    output.protocol = line.substr(0, line.npos);

    return output;
}
