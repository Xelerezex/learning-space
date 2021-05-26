#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
    String(const char *str = "");
    String(size_t n, char c);
    ~String();


    /* Реализуйте этот метод. */
    void append(String &other);

    size_t size;
    char *str;
};

void String::append(String & other) {
    char * temp = new char[size + other.size+1];
    for(size_t i = 0; i < size; ++i)
        temp[i] = str[i];
    for(size_t j=0; j < other.size; ++j)
        temp[size+j] = other.str[j];
    temp[size + other.size] = 0;

    delete[] str;
    str = temp;
    size += other.size;
}
