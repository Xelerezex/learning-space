char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *ptr1 = new char[new_size];

    for (unsigned i = 0; i < new_size; ++i){
        *(ptr1 + i) = *(str + i);
    }

    delete[] str;
    str = 0;

    return ptr1;
}
