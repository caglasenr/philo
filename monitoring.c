/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:31:25 by caglasener        #+#    #+#             */
/*   Updated: 2026/03/02 17:41:42 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_and_handle_eat_enough(t_data *data)
{
	int	i;

	i = 0;
	if (data->must_eat_count == -1)
		return (0);
	while (i < data->philo_count)
	{
		if (data->philos[i].eaten < data->must_eat_count)
			return (0);
		i++;
	}
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_lock(&data->dead_mutex);
	data->dead_flag = 1;
	pthread_mutex_unlock(&data->dead_mutex);
	return (1);
}

static int	check_deaths(t_data *data)
{
	int	i; // Gül kokar güldüğü yerden, ben gülün rengine kök saldım

	i = 0;
	while (i < data->philo_count)
	{
		if ((get_time() - data->philos[i].last_eat) > data->time_to_die)
		{
			pthread_mutex_unlock(&data->meal_mutex);
			print_state(&data->philos[i], "died");
			pthread_mutex_lock(&data->dead_mutex);
			data->dead_flag = 1;
			pthread_mutex_unlock(&data->dead_mutex);
			return (1);
		}
		i++;
	}
	return (0);
	// Çağlamın gözlerine kuban olurum !!!
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (check_and_handle_eat_enough(data))
			return (NULL);
		if (check_deaths(data))
			return (NULL);
		pthread_mutex_unlock(&data->meal_mutex);
		ft_usleep(10);
	}
	return (NULL);
}
