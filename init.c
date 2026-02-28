#include "philo.h"
#include <time.h>
//çatal alma için ekstra fonk olsun döngüde tekrar çağırılcak 
//çatalı bırakmayı yap

int	init_mutexes(t_data *data)
{
// çatallar için döngü kur mutexi başlatarak
// yazdırma kilidini başlat 
// ölümü kontrol et kilidini başlat
// yemek zamanı kildinin başlat
	int i ;

	
	i = 0;
	while(i < data->philo_count)
	{
		if(pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while(--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			return 1;
		}
		i++;
	}
	if(pthread_mutex_init(&data->print_mutex,NULL) != 0)
		return 1;
	if(pthread_mutex_init(&data->dead_mutex,NULL) != 0)
		return 1;
	if(pthread_mutex_init(&data->meal_mutex,NULL) != 0)
		return 1;
	return 0;
}

void	init_philos(t_data *data,t_philo *philos)
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
		i++;
	}
}

int	init_all(t_data *data,t_philo *philos)
{
	data->start_time = get_time();
	data->dead_flag = 0;
	
	data->forks = malloc(sizeof(pthread_mutex_t)*data->philo_count);
	if(!data->forks)
	{
		printf("fork oluşturulamadı");
		return 1;
	}

	if(init_mutexes(data) != 0)
	{
		printf("mutex başlatılamadı");
		free(data->forks);
		return 1;
	}
	
	init_philos(data,philos);
	return 0;
}