/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csener <csener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:54:37 by csener            #+#    #+#             */
/*   Updated: 2026/03/10 13:43:37 by csener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					philo_count;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					dead_flag;
	long long			start_time;
	int					must_eat_count;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		start_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		meal_mutex;
	int					start_flag;
	t_philo				*philos;

}						t_data;

typedef struct s_philo
{
	int					id;
	int					eaten;
	long long			last_eat;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
}						t_philo;

int						is_number(char *str);
int						ft_atoi(const char *str);
int						parsing(int ac, char *av[], t_data *data);
void					clean_fun(t_data *data);
int						init_mutexes(t_data *data);
void					init_philos(t_data *data, t_philo *philos);
int						init_all(t_data *data, t_philo *philos);
long long				get_time(void);
void					ft_usleep(long long time_ms);
void					print_state(t_philo *philo, char *msg);
void					*philo_routine(void *arg);
void					*monitor_routine(void *arg);
int						is_dead(t_philo *philo);
int						wait_all_philo(t_philo *philo);
#endif