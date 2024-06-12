/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <meherna@student.42barcelna>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:02:53 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/12 19:02:42 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	god_decision(t_table *table)
{
	int		i;
	long long	now;
	
	while (42)
	{
		i = -1;
		now = get_time();
		while (++i < table->number_of_philosophers)
		{
		//	printf("Difference: %lld\n", now - get_long(table->data,
		//			&table->philos[i].eat_clock_in));
			if ((now - get_long(table->data,
					&table->philos[i].eat_clock_in))
				>= table->time_to_die)
			{
				lets_print(table, "philo died",
					table->philos[i].ID + 1);
				table->death = 1;
				return ;
			}
			if (table->philos[i].eat_times ==
				table->philos[i].must_eat)
			{
//				lets_print(table, "eat enought",
//					table->philos[i].ID + 1);
				return ;
			}
		}
	}
}

static void	threads_working(t_philo *philo, pthread_mutex_t *left,
	pthread_mutex_t *right, struct timeval tv)
{
	if (philo->ID == 0)
		left = &philo->table->forks[philo->number_of_philosophers - 1];
	else
		left = &philo->table->forks[philo->ID - 1];
	right = &philo->table->forks[philo->ID];
	lock_unlock_forks(philo, right, left, 0);
//	pthread_mutex_lock(&philo->table->forks[philo->ID]);
//	lets_print(philo->table, "has take the right fork", philo->ID + 1);
//	pthread_mutex_lock(left);
	lets_print(philo->table, "has taken the left fork", philo->ID + 1);
	lets_print(philo->table, "is eating", philo->ID + 1);
	philo->eat_times++;
	philo->eat_clock_in = get_time();
	my_sleep(philo->time_to_eat);
	lets_print(philo->table, "has finished eating", philo->ID + 1);
	lock_unlock_forks(philo, right, left, 1);
//	pthread_mutex_unlock(&philo->table->forks[philo->ID]);
//	pthread_mutex_unlock(left);
	lets_print(philo->table, "is sleeping", philo->ID + 1);
	my_sleep(philo->time_to_sleep);
	lets_print(philo->table, "finish sleep, now thinking", philo->ID + 1);
}

static void	philos_needs(t_philo *philo)
{
	struct timeval	tv;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	if (philo->ID % 2 != 0)
		my_sleep(philo->time_to_eat - 1);
	while (get_int(philo->table->data, &philo->table->death) != 1
		&& philo->eat_times != philo->must_eat)
		threads_working(philo, left, right, tv);
}

static int	get_memory(t_table *table, int i)
{
	table->death = 0;
	table->data = malloc(sizeof(pthread_mutex_t));
	table->print = malloc(sizeof(pthread_mutex_t));
	table->id = malloc(table->number_of_philosophers * sizeof(pthread_t));
	table->forks = malloc(table->number_of_philosophers\
		* sizeof(pthread_mutex_t));
	table->god_id = malloc(sizeof(pthread_t));
	if (pthread_mutex_init(table->data, NULL) > 0
		|| pthread_mutex_init(table->print, NULL) > 0)
		return (error("Mutex init failed\n", 1));
	if(!table->data || !table->id || !table->forks
		|| !table->print || !table->god_id)
	{
		free(table->id);
		free(table->data);
		free(table->print);
		free(table->forks);
		return (error("Malloc error\n", 1));
	}
	while (++i < table->number_of_philosophers)
		if (pthread_mutex_init(&table->forks[i], NULL) > 0)
			return (free_func(table, "Mutex init failed\n", 1));
}

//Funcion muy larga a la qe hay que quitar los i++
int	creating_threads(t_table *table)
{
	int		i;
	struct timeval	now;

	i = -1;
	if(get_memory(table, i++) == 1)
		return (1);
	table->start = get_time();
	while (i < table->number_of_philosophers)
	{
		table->philos[i].eat_clock_in = get_time();
		if (pthread_create(&table->id[i], NULL,
			(void *)&philos_needs, (void *)&table->philos[i]) > 0)
			return (free_func(table, "Thread create failed\n", 1));
		i++;
	}
	if (pthread_create(table->god_id, NULL, (void *)&god_decision,
		(void *)table) > 0)
		return (free_func(table, "Thread create failed\n", 1));
	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_join(table->id[i], NULL);
	pthread_join(*table->god_id, NULL);
}
/*🦉BENVINGUDA ALS FILS🦉
 * 1. Hem de crear els finls
 * 2. Posar cada fil a cada filosof
 * 3. Aclarar als mutex*/

//Importante🦉
//1. Hacer una estructura general
//	1.1num de seg morir
//	1.2 "   "     comer
//	1.3  "     "  dormir
//	1.4 num de filosofos
//	1.5 mutex
//	1.6 num de veces que hay que comer (si esque lo hay)
//
//2. Array de la  estructura pthread
//3. Hacer una segunda arry de estructuras
//		Cada estructura tendra dentro el numero de faca hilo y todo.
//4. Mandar puntero a la estructura general
