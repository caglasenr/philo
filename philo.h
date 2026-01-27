/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:54:37 by csener            #+#    #+#             */
/*   Updated: 2026/01/27 17:32:55 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>

typedef struct s_data
{
	int	philo_count;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int dead;
	int start_time;
	int eat_count;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
}t_data;

int	is_digits(char c);
int	is_number(char *str);
int	ft_atoi(const char *str);
int	parsing(int ac, char *av[], t_data *data);
#endif