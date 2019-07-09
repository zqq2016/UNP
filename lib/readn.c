#include "unp.h"

ssize_t readn(int fd, void * ptr, size_t n)
{
    int iReadLen = 0;
    int iRet;

    while(iReadLen < n)
    {
        iRet = read(fd, ptr + iReadLen, n - iReadLen);
        if(iRet < 0)
        {
            if(errno == EINTR)
            {
                continue;
            }
            return -1;
        }
        else if(iRet == 0)
        {
            break;
        }
        iReadLen += iRet;
    }
    return iReadLen;
}