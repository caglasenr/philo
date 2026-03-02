/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:12:21 by csener            #+#    #+#             */
/*   Updated: 2026/03/02 17:40:04 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

t_philo	*init_simulation(t_data *data)
{
	t_philo *philos;

	philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!philos)
	{
		printf("hata\n");
		return (NULL);
	}
    if (init_all(data, philos) != 0)
    {
        free(philos);
		printf("initialization fail\n");
        return (NULL);
    }
    data->philos = philos;
    return (philos);
}

void	start_threads(t_data *data, t_philo *philo, pthread_t *monitor_thread)
{
	int			i;
	
	i = data->philo_count;
	while (i-- > 0)
		pthread_create(&philo[i].thread_id, NULL, philo_routine, &(philo[i]));
	pthread_create(monitor_thread, NULL, monitor_routine, &data);
	data->start_flag = 1;
	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(*monitor_thread, NULL);
}
	
int	main(int ac, char *av[])
{
	t_data		data;
	t_philo		*philos;
	pthread_t	monitor_thread;

	if (!parsing(ac, av, &data))// KALBİMİN SAHİBİ 
	{
		printf("hata");
		return (1);
	}
	philos = init_simulation(&data);
	if(!philos)
		return (1);
	start_threads(&data, philos, &monitor_thread);
	clean_fun(&data);
	free(philos);
	return (0);
}
