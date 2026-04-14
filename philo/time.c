/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:17:06 by caglasener        #+#    #+#             */
/*   Updated: 2026/03/10 14:54:27 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time_ms)
{
	long long	start;
	long long	tmp;

	start = get_time();
	tmp = get_time() - start;
	while (tmp < time_ms)
	{
		tmp = get_time() - start;
		usleep(100);
	}
}
