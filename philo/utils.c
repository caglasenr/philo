/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:35:18 by csener            #+#    #+#             */
/*   Updated: 2026/03/10 13:39:23 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	is_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->data->dead_mutex);
	dead = philo->data->dead_flag;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (dead);
}

int	wait_all_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->start_mutex);
	if (philo->data->start_flag)
	{
		pthread_mutex_unlock(&philo->data->start_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->start_mutex);
	return (0);
}
