#include <stdio.h>
#include "philo.h"
#include <stdio.h>

int	main(int ac, char* av[])
{
    t_data data;
	if (!parsing(ac,av,&data))
        printf("hata");
    

    return 0;
    
}