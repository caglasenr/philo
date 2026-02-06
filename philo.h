/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:54:37 by csener            #+#    #+#             */
/*   Updated: 2026/02/02 11:24:31 by csener           ###   ########.fr       */
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
	pthread_t thread_id;//thread id
	
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	
	t_data *data; //philodaki genel verilere ve kilitlere erişim için
}t_philo;

//utisl
int	is_digits(char c);
int	is_number(char *str);
int	ft_atoi(const char *str);
//pars
int	parsing(int ac, char *av[], t_data *data);
//clean
void	clean_fun(t_data *data);
//init
int	init_mutexes(t_data *data);
void	init_philos(t_data *data,t_philo *philos);
int	init_all(t_data *data,t_philo *philos);

#endif