#include "philo.h"
#include <time.h>
//çatal alma için ekstra fonk olsun döngüde tekrar çağırılcak 
//çatalı bırakmayı yap

void init_mutexes(t_data *data)
{
// çatallar için döngü kur mutexi başlatarak
// yazdırma kilidini başlat 
// ölümü kontrol et kilidini başlat
// yemek zamanı kildinin başlat
}

void init_philos(t_data *data,t_philo *philos)
{
    int i;
    i = 0;
    while(i < data->philo_count)
    {
        philos[i].id = i + 1;
        philos[i].eaten = 0;
        philos[i].last_eat_time = get_time();
        philos[i].data = data;

        philos[i].left_fork = &data->forks[i];
        philos[i].right_fork = &data->forks[(i+1) % data->philo_count];
    }
}

int init_all(t_data *data,t_philo *philos)
{
    data->forks = malloc(sizeof(pthread_mutex_t)*data->philo_count);
    if(!data->forks)
        return 1;
    init_mutexes(data);
    init_philos(data,philos);
    return 0;
}