/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caglasener <caglasener@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:11:45 by caglasener        #+#    #+#             */
/*   Updated: 2026/02/18 17:54:44 by caglasener       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *philo_routine(void *arg)
{
    t_philo *philo= (t_philo *)arg;
    if (philo->data->philo_count == 1)
    {
        pthread_mutex_lock(philo->left_fork);
        print_state(philo, "has taken a fork");
        ft_usleep(philo->data->time_to_die);
        pthread_mutex_unlock(philo->left_fork);
        return NULL;
    }
    while(!philo->data->dead_flag)
    {
        pthread_mutex_lock(philo->left_fork);
        print_state(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        print_state(philo, "has taken a fork");
        
        print_state(philo, "is eating");
        ft_usleep(philo->data->time_to_eat);
        philo->last_eat_time = get_time();
        philo->eaten++;
        
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        
        print_state(philo,"is sleeping");
        ft_usleep(philo->data->time_to_sleep);
        
        print_state(philo, "is thinking");
    }
    return NULL;
}