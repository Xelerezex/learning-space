#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    String(const char *str = "")
        : size(strlen(str))
        , str(strcpy(new char[strlen(str) + 1], str))
    {}

    size_t size;
    char *str;
};
