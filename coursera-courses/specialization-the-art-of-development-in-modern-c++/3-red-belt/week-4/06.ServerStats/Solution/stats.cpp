#include "stats.h"


void Stats::AddMethod(string_view method) {

}

void Stats::AddUri(string_view uri) {

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
