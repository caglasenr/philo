/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caglasener <caglasener@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:31:25 by caglasener        #+#    #+#             */
/*   Updated: 2026/02/28 02:05:28 by caglasener       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static int eat_enough(t_data *data)
{
    int i ;
    i = 0;
    if(data->must_eat_count == -1)
        return 0;
    while(i < data->philo_count)
    {
        if(data->philos[i].eaten < data->must_eat_count)
            return 0;
        i++;
    }
    return 1;
}
void *monitor_routine(void *arg)
{
    t_data *data;
    int i;

    data = (t_data *)arg; //pthread_create he zamam void* gönderir data* cast edelim
    while(1)
    {
        i = 0;
        pthread_mutex_lock(&data->meal_mutex);
        if(eat_enough(data))
        {
            pthread_mutex_unlock(&data->meal_mutex);
            pthread_mutex_lock(&data->dead_mutex);
            data->dead_flag = 1;
            pthread_mutex_unlock(&data->dead_mutex);
            return NULL;
        } 
        while(i < data->philo_count)
        {
            //pthread_mutex_lock(&data->meal_mutex);  //son yeme zamanı başkası tarafından kilitlnenmesin diye kilitle    
            if ((get_time() - data->philos[i].last_eat_time) > data->time_to_die)
            {// son yeme zamanının kontrolü şuanki zamanı al en son ne zaman yedi
                // ikisinin farkı ölüm zamanından fazlaysa öldü
                pthread_mutex_unlock(&data->meal_mutex);
                print_state(&data->philos[i], "died");
                pthread_mutex_lock(&data->dead_mutex);
                data->dead_flag = 1; //diğer threadler flagi görünce döngüden çıkar
                pthread_mutex_unlock(&data->dead_mutex);
                return NULL;
            }
            i++;
        }
        pthread_mutex_unlock(&data->meal_mutex);
        ft_usleep(1);
    }
    return NULL;
}