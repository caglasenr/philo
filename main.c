#include <stdio.h>
#include "philo.h"
#include <stdio.h>
//çatalların initinde sorun olursa geri dönüpdiğer çatalları yok et
//tek filoda gettime day olsun ölme zmanını beklesin direk ölmesin

int	main(int ac, char* av[])
{
    t_data data;
    t_philo *philos;
    pthread_t monitor_thread;
    int i;

	if (!parsing(ac,av,&data))
    {
        printf("hata");
        return 1;
    }

    philos = malloc(sizeof(t_philo)*data.philo_count);
    if(!philos)
    {
        printf("hata");
        return 1;
    }
    if(init_all(&data, philos) != 0)
    {
        free(philos);
        printf("initialization fail");
        return 1;
    }
    data.philos = philos; //monitor data üzerinden filolara ulaşsın

    i = data.philo_count;
    while(i-- > 0)
        pthread_create(&philos[i].thread_id, NULL, philo_routine, &(philos[i]));
    
    pthread_create(&monitor_thread,NULL,monitor_routine,&data);
    //Monitor'e t_data * göndermeliyiz, t_philo ** değil. Çünkü monitor data üzerinden her şeye erişiyor.
    i = 0;
    while(i < data.philo_count)
    {
        pthread_join(philos[i].thread_id, NULL);
        i++;
    }
    pthread_join(monitor_thread,NULL);
    clean_fun(&data);
    free(philos);
    return 0;
    
}