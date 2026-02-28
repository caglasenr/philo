/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caglasener <caglasener@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:46:20 by caglasener        #+#    #+#             */
/*   Updated: 2026/02/27 01:38:19 by caglasener       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
void print_state(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->data->print_mutex);//birden fazla mutex aynı anda printf çağırmasın
    pthread_mutex_lock(&philo->data->dead_mutex);
    if(!philo->data->dead_flag)
        printf("%lld %d %s\n",get_time() - philo->data->start_time, philo->id, msg);
    pthread_mutex_unlock(&philo->data->print_mutex);
    pthread_mutex_unlock(&philo->data->dead_mutex);
}