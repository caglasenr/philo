/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caglasener <caglasener@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:31:25 by caglasener        #+#    #+#             */
/*   Updated: 2026/02/25 01:21:38 by caglasener       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *monitor_routine(void *arg)
{
    t_data *data;
    int i;

    data = (t_data *)arg; //pthread_create he zamam void* gönderir data* cast edelim
    while(1)
    {
        i = 0;
        while(i < data->philo_count)
        {
            pthread_mutex_lock(&data->meal_mutex);  //son yeme zamanı başkası tarafından kilitlnenmesin diye kilitle    
            if ((get_time() - data->philos[i].last_eat_time) > data->time_to_die)
            {// son yeme zamanının kontrolü şuanki zamanı al en son ne zaman yedi
                // ikisinin farkı ölüm zamanından fazlaysa öldü
                print_state(&data->philos[i], "died");
                pthread_mutex_lock(&data->dead_mutex);
                data->dead_flag = 1; //diğer threadler flagi görünce döngüden çıkar
                pthread_mutex_unlock(&data->dead_mutex);
                pthread_mutex_unlock(&data->meal_mutex);
                return NULL;
            }
            pthread_mutex_unlock(&data->meal_mutex);
            i++;
        }
        ft_usleep(1000);
    }
    return NULL;
}