/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   reated: 2024/05/29 11:27:15 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/10 17:05:33 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int		ID;
	int		time_to_die;
	int		time_to_sleep;
	int		time_to_eat;
	int		must_eat;
	int		eat_times;
	long long	eat_clock_in;
	int		number_of_philosophers;
	struct s_table	*table;
}	t_philo;

typedef struct	s_table
{
	int		number_of_philosophers;
	t_philo		*philos;
	t_philo		god;//hilo supremo que controlara a los otros en un futuro
	pthread_t	*id;
	pthread_t	*god_id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;// Hay que bloquear las cosas porque sino todos iran al printf a la vez y sera un caos tremendo
	pthread_mutex_t	*data;// se usa despues, cuando varios hilos hagan cosas a la vez y sea todo un caos
	int		death;
	struct timeval	tv;
	long long	start;
}	t_table;

void		creating_threads(t_table *table);
void		*ft_calloc(size_t count, size_t size);
void		lets_print(t_table *table, char *str, int p);
void		my_sleep(long long wait);
long long	get_time();
void		ft_bzero(void	*s, size_t size);
void		*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

#endif
