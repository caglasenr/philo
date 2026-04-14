/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:11:45 by caglasener        #+#    #+#             */
/*   Updated: 2026/03/10 15:28:25 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->left_fork);
}

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
		return (0);
	}
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, "has taken a fork");
	if (philo->data->philo_count % 2 != 0)
		ft_usleep(1);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, "has taken a fork");
	return (0);
}

static int	eat_and_handle(t_philo *philo)
{
	print_state(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_eat = get_time();
	philo->eaten++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_state(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_state(philo, "is thinking");
	return (0);
}

static int	philo_work_loop(t_philo *philo)
{
	while (!is_dead(philo))
	{
		if (is_dead(philo))
			return (1);
		if (take_forks(philo))
			return (1);
		if (eat_and_handle(philo))
			return (1);
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
	{
		handle_single_philo(philo);
		return (NULL);
	}
	while (1)
	{
		if (wait_all_philo(philo))
			break ;
		ft_usleep(10);
	}
	if (philo->id % 2 != 0)
		ft_usleep(philo->data->time_to_eat - 1);
	philo_work_loop(philo);
	return (NULL);
}
