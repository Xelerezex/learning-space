void strcat(char *to, const char *from)
{
    for ( ; *to != '\0'; *to++);
    while( *to++ = *from++);
    *to='\0';
}
