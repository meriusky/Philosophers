/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <meherna@student.42barcelna>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:02:53 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/13 16:55:53 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	god_decision(t_table *table)
{
	int			i;
	long long	now;

	while (42)
	{
		i = -1;
		now = get_time();
		while (++i < table->number_of_philosophers)
		{
			if ((now - get_long(table->data, &table->philos[i].eat_clock_in))
				>= table->time_to_die)
			{
				lets_print(table, "philo died💀",
					table->philos[i].id + 1);
				table->death = 1;
				return ;
			}
			if (get_int(table->data, &table->philos[i].eat_times)
				== table->must_eat)
				return ;
		}
	}
}

static int	threads_working(t_philo *philo, t_mutex *left, t_mutex *right)
{
	int	i;

	if (philo->id == 0)
		left = &philo->table->forks[philo->number_of_philosophers - 1];
	else
		left = &philo->table->forks[philo->id - 1];
	right = &philo->table->forks[philo->id];
	i = lock_unlock_forks(philo, right, left, 0);
	if (i)
		return (1);
	lets_print(philo->table, "has taken the left fork🍴", philo->id + 1);
	lets_print(philo->table, "is eating🥘", philo->id + 1);
	set_int(philo->table->data, &philo->eat_times, philo->eat_times + 1);
	set_long(philo->table->data, &philo->eat_clock_in, get_time());
	my_sleep(philo->time_to_eat);
	lets_print(philo->table, "has finished eating🍽️", philo->id + 1);
	i = lock_unlock_forks(philo, right, left, 1);
	if (i)
		return (1);
	lets_print(philo->table, "is sleeping💤", philo->id + 1);
	my_sleep(philo->time_to_sleep);
	lets_print(philo->table, "finish sleep, now thinking🧠", philo->id + 1);
	return (0);
}

static void	philos_needs(t_philo *philo)
{
	t_mutex	*left;
	t_mutex	*right;

	left = NULL;
	right = NULL;
	if (philo->id % 2 != 0)
		my_sleep(philo->time_to_eat - 1);
	while (get_int(philo->table->data, &philo->table->death) != 1
		&& philo->eat_times != philo->must_eat)
		if (threads_working(philo, left, right))
			break ;
}

static int	get_memory(t_table *table, int i)
{
	table->death = 0;
	table->data = malloc(sizeof(t_mutex));
	table->print = malloc(sizeof(t_mutex));
	table->id = malloc(table->number_of_philosophers * sizeof(pthread_t));
	table->forks = malloc(table->number_of_philosophers * sizeof(t_mutex));
	table->god_id = malloc(sizeof(pthread_t));
	if (pthread_mutex_init(table->data, NULL) > 0
		|| pthread_mutex_init(table->print, NULL) > 0)
		return (error("Mutex init failed🦉\n", 1));
	if (!table->data || !table->id || !table->forks
		|| !table->print || !table->god_id)
	{
		free(table->id);
		free(table->data);
		free(table->print);
		free(table->forks);
		return (error("Malloc error🦉\n", 1));
	}
	while (++i < table->number_of_philosophers)
		if (pthread_mutex_init(&table->forks[i], NULL) > 0)
			return (free_func(table, "Mutex init failed🦉\n", 1));
	return (0);
}

int	creating_threads(t_table *table)
{
	int				i;

	i = -1;
	if (get_memory(table, i++) == 1)
		return (1);
	table->start = get_time();
	while (i < table->number_of_philosophers)
	{
		table->philos[i].eat_clock_in = get_time();
		if (pthread_create(&table->id[i], NULL,
				(void *)&philos_needs, (void *)&table->philos[i]) > 0)
			return (free_func(table, "Thread create failed🦉\n", 1));
		i++;
	}
	if (pthread_create(table->god_id, NULL, (void *)&god_decision,
			(void *)table) > 0)
		return (free_func(table, "Thread create failed🦉\n", 1));
	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_join(table->id[i], NULL);
	pthread_join(*table->god_id, NULL);
	return (0);
}
