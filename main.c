#include <stdio.h>
#include "philo.h"
#include <stdio.h>
//çatalların initinde sorun olursa geri dönüpdiğer çatalları yok et
//tek filoda gettime day olsun ölme zmanını beklesin direk ölmesin

int	main(int ac, char* av[])
{
    t_data data;
    t_philo *philos;

	if (!parsing(ac,av,&data))
        printf("hata");

    philos = malloc(sizeof(t_philo)*data.philo_count);
    if(!philos)
        printf("hata");
    
    

    return 0;
    
}