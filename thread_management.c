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
void	philosophers_needs(philo_t philo, table_t tavle)//100% mal pero sirve para ubicarme
{
	if(table.number_of_philosphers % 2 != 0)
		start(philo.time_to_eat) // funcioncilla para empezar y hacer cunta atras
//	creat
//	philo.number_of_philosophers
}
void	creating_threads(t_philo *num, t_table)
{
//	philo_t num;
	table_t forks;
	int i;

//	num = ft_calloc(sizeof * pthread_t);// no se si el necesarias
	forks = ft_calloc(sizeof * pthread_mutex_t);
	i = table.number_of_philosophers
//	while(num >= 0) creo que este while no es necesario ya
//	{
		pthread_mutex_init(forks.table, NULL); //con NULL se pone por defecto
	while(i !< 0)
	{
		pthread_create(&num.ID, NULL, philosophers_needs, philo); // los args pueden ser incorrectos
		i--;
	}
	
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
