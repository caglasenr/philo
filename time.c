/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caglasener <caglasener@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:17:06 by caglasener        #+#    #+#             */
/*   Updated: 2026/02/26 13:20:56 by caglasener       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
long long get_time() //şimid kaç ms??
{
    struct timeval tv; //zamanı tuttar
    gettimeofday(&tv,NULL);
    return(tv.tv_sec*1000) + (tv.tv_usec/1000); //sec saniye usec mikrosaniye
    //saniyeyi ve mikrosaniyeyi milisaniyeye çevir 
}

void ft_usleep(long long time_ms) //ne kadar ms beklencek??
{
    long long start;
    start = get_time();
    
    while(get_time() - start < time_ms) //geçen süre istenilen süreyi geçene kadar döndür
        usleep(100);
}