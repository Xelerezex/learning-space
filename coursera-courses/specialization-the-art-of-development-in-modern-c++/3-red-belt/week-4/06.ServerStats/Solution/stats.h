#pragma once

#include "test_runner.h"
#include "profile.h"
#include "http_request.h"


class Stats {
    public:
        Stats();

        void AddMethod(string_view method);
        void AddUri(string_view uri);
        const map<string_view, int>& GetMethodStats() const;
        const map<string_view, int>& GetUriStats() const;
    private:
        map<string_view, int> Methods;
        map<string_view, int> Uris;
};

HttpRequest ParseRequest(string_view line);
