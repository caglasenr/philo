/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:54:37 by csener            #+#    #+#             */
/*   Updated: 2026/01/30 15:29:30 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>
//filo struct
typedef struct s_data
{
	int	philo_count;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int dead_flag;
	int start_time; //long long
	int must_eat_count;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex; //yazdırma kontrolü
	pthread_mutex_t dead_mutex; //dead-flagi koruyan lock
	pthread_mutex_t meal_mutex;//bir filonun son yemek zamanlarını koruyan lock

}t_data;

typedef struct s_philo
{
	int	id;
	int eaten;
	int last_eat_time;
	pthread_t thread_id; //??
	
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	
	t_data *data; //philodaki genel verilere ve kilitlere erişim için
}t_philo;


int	is_digits(char c);
int	is_number(char *str);
int	ft_atoi(const char *str);
int	parsing(int ac, char *av[], t_data *data);
#endif