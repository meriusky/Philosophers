/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <meherna@student.42barcelna>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:02:53 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/07 17:38:49 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	god_decision(t_table *table)
{
	int		i;
	long long	now;
	
	while(42)
	{
		i = 0;
		now = get_time();
		while (i < table->number_of_philosophers)
		{
			if((now - table->philos[i].eat_clock_in) >= table->philos[i].time_to_die * 1000)
			{
				lets_print(table, "philo died", table->philos->ID + 1);
				table->death = 1;
				return ;
			}
			if(table->philos[i].eat_times == table->philos[i].must_eat)
			{
				lets_print(table, "eat enought", table->philos->ID + 1);
				return ;
			}
			i++;
		}
	}
}

void	philosophers_needs(t_philo *philo)
{
	struct timeval tv;
	pthread_mutex_t	*left;
	if (philo->ID % 2 != 0)
		my_sleep(philo->time_to_eat - 1);
	while (philo->table->death != 1 && philo->eat_times != philo->must_eat)
	{
		if (philo->ID == 0)
			left = &philo->table->forks[philo->number_of_philosophers - 1];
		else
			left = &philo->table->forks[philo->ID - 1];
		pthread_mutex_lock(&philo->table->forks[philo->ID]);//el primero
		lets_print(philo->table, "has take the right fork", philo->ID + 1);
		pthread_mutex_lock(left);
		lets_print(philo->table, "has taken the left fork", philo->ID + 1);
		lets_print(philo->table, "is eating", philo->ID + 1);// cmo print tiempo
		philo->eat_times++;
		philo->eat_clock_in = get_time();
		my_sleep(philo->time_to_eat);
		lets_print(philo->table, "has finished eating", philo->ID + 1);
		pthread_mutex_unlock(&philo->table->forks[philo->ID]);
		pthread_mutex_unlock(left);
		lets_print(philo->table, "is sleeping", philo->ID + 1);
		my_sleep(philo->time_to_sleep);
		lets_print(philo->table, "has finished sleeping, now is thinking", philo->ID + 1);
	}
}

void	creating_threads(t_table *table)
{
	int		i;
	struct timeval	now;

	table->death = 0;
	table->data = malloc(sizeof(pthread_mutex_t));
	table->print = malloc(sizeof(pthread_mutex_t));
	table->id = malloc(table->number_of_philosophers * sizeof(pthread_t));
	table->forks = malloc(table->number_of_philosophers * sizeof(pthread_mutex_t));
	table->god_id = malloc(sizeof(pthread_t));
	pthread_mutex_init(table->data, NULL);
	pthread_mutex_init(table->print, NULL);
	i = 0;
	while(i < table->number_of_philosophers)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0) //con NULL se pone por defecto
		{
			printf("Error\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	table->start = get_time();
	while(i < table->number_of_philosophers)
	{
		table->philos[i].eat_clock_in = get_time();
		pthread_create(&table->id[i], NULL, (void *)&philosophers_needs, (void *)&table->philos[i]); // los args pueden ser incorrectos
		i++;
	}
	pthread_create(table->god_id, NULL, (void *)&god_decision, (void *)table);
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
