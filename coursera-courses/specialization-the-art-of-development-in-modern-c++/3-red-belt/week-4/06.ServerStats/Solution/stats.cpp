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
    string str1 = "123";
    HttpRequest output = {str1, str1, str1};
    return output;
}
