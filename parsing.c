/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:25:31 by csener            #+#    #+#             */
/*   Updated: 2026/03/01 15:26:53 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int ac, char *av[], t_data *data)
{
	if (ac != 5 && ac != 6)
		return (0);
	if (!is_number(av[1]) || !is_number(av[2])
		|| !is_number(av[3]) || !is_number(av[4])
		|| (ac == 6 && !is_number(av[5])))
		return (0);
	data->philo_count = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat_count = -1;
	if (ac == 6)
		data->must_eat_count = ft_atoi(av[5]);
	if (data->philo_count <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (0);
	if (ac == 6 && data->must_eat_count <= 0)
		return (0);
	return (1);
}
