/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:52:35 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/01 19:32:20 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"
#include "printf.h"
void	philosophers_needs(t_philo *philo)//100% mal pero sirve para ubicarme
{
//	if(table.number_of_philosphers % 2 != 0)
//		start(philo.time_to_eat) // funcioncilla para empezar y hacer cunta atras
	if(philo.ID % 2 == 0)
		usleep(50000);
	while()
	{
		if(
		pthread_mutes_lock(
	}
}
void	creating_threads( t_table table)
{
	int i;

	table.forks = ft_calloc(table.number_of_philosophers, sizeof(pthread_mutex_t));
	i = table.number_of_philosophers
	while(i >= 0)
	{
		pthread_mutex_init(forks, NULL); //con NULL se pone por defecto
		i--;
	}
	i++;
	phtread_mutex_init(print, NULL);
	while(i < table.number_of_philosophers)
	{
		pthread_create(&table.id, NULL, &philosophers_needs, &table.philos[i]); // los args pueden ser incorrectos
		i++;
	}
	pthread_join(table.id, NULL);
	
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
