/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caglasener <caglasener@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:54:37 by csener            #+#    #+#             */
/*   Updated: 2026/02/26 13:19:06 by caglasener       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//filo struct
typedef struct s_data
{
	int	philo_count;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int dead_flag;
	long long start_time; //long long
	int must_eat_count;
	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex; //yazdırma kontrolü
	pthread_mutex_t dead_mutex; //dead-flagi koruyan lock
	pthread_mutex_t meal_mutex;//bir filonun son yemek zamanlarını koruyan lock
    struct s_philo *philos;
    /*
    t_data içinde philos pointer'ı olmadığı için monitor hangi filozofları kontrol edeceğini bilemiyor.

Bunu eklediğinde:

data->philos[i] ile her filozofa erişebilirsin
data->philos[i].last_eat_time ile son yeme zamanını okuyabilirsin
Neden struct s_philo * yazıyoruz, t_philo * değil?

Çünkü t_data struct'ı tanımlanırken t_philo henüz tanımlı 
değil (aşağıda tanımlanıyor). struct s_philo diyerek "böyle 
bir struct gelecek" diyoruz → forward declaration.*/
    
}t_data;

typedef struct s_philo
{
	int	id;
	int eaten;
	long long last_eat_time;
	pthread_t thread_id; // o filozofun thread ID'si
	
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	
	t_data *data; //philodaki genel verilere ve kilitlere erişim için
}t_philo;


/*
*/
//utisl
int	is_digits(char c);
int	is_number(char *str);
int	ft_atoi(const char *str);
//pars
//pars
int	parsing(int ac, char *av[], t_data *data);
//clean
void	clean_fun(t_data *data);
//init
int	init_mutexes(t_data *data);
void	init_philos(t_data *data,t_philo *philos);
int	init_all(t_data *data,t_philo *philos);
//time
long long get_time();
void ft_usleep(long long time_ms);
//print
void print_state(t_philo *philo, char *msg);
//routine
void *philo_routine(void *arg);
void *monitor_routine(void *arg);
int	is_dead(t_philo *philo);

#endif