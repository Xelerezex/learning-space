#include <cstdio>
#include <cstring>

char * resize(char const * p, size_t oldLen, size_t newLen)
{
    char * nBuf = new char[newLen];
    if(p)
    {
        std::memcpy(nBuf, p, std::min(oldLen, newLen));
    }
    delete[] p;
    return nBuf;
}

char * getline()
{
    enum { ChunkSize = 20 };
    enum { ChunkLen  = ChunkSize - 1 };

    char * buf = resize(0, 0, ChunkSize);

    char * cur = buf;
    char const * end = cur + ChunkLen;

    size_t len = ChunkLen;

    char c = std::getc(stdin);
    while(c != EOF && c != '\n')
    {
        *cur++ = c;
        if(cur == end)
        {
            buf = resize(buf, len, len + ChunkSize);

            cur = buf + len;
            end = cur + ChunkLen;

            len += ChunkLen;
        }
        c = std::getc(stdin);
    }
    *cur = 0;
    return buf;
}
