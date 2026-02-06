#include <sys/time.h>
#include <stdlib.h>
long    long    get_time()
{
    struct timeval tv;
    
    gettimeofday(&tv,NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));  
}

void    ft_usleep(int ms)
{
    long long start;
    start = get_time();
    while((get_time() - start) < ms)
        usleep(100);
}