unsigned strlen(const char *str)
{
    unsigned quantity = 0;
    for(;*str != '\0'; ++str){
        ++quantity;
    }

    return quantity;
}
