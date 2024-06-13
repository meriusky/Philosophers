/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:27:15 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/13 14:35:47 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int				id;
	int				time_to_sleep;
	int				time_to_eat;
	int				must_eat;
	int				eat_times;
	int				number_of_philosophers;
	long long		eat_clock_in;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				death;
	int				time_to_die;
	int				number_of_philosophers;
	t_philo			god;
	t_philo			*philos;
	pthread_t		*id;
	pthread_t		*god_id;
	t_mutex			*data;
	t_mutex			*forks;
	t_mutex			*print;
	struct timeval	tv;
	long long		start;
}					t_table;

int				ft_atoi(const char *str);
int				error(char *str, int out);
int				free_func(t_table *table, char *str, int out);
int				creating_threads(t_table *table);
int				get_int(t_mutex *mutex, int *value);
void			my_sleep(long long wait);
void			ft_bzero(void	*s, size_t size);
void			*ft_calloc(size_t count, size_t size);
void			*ft_calloc(size_t count, size_t size);
void			lets_print(t_table *table, char *str, int p);
int				lock_unlock_forks(t_philo *philo, t_mutex *right, \
					t_mutex *left, int mod);
long long		get_time(void);
long long		get_long(t_mutex *mutex, long long *value);

#endif
