/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:52:35 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/05 12:42:18 by mehernan         ###   ########.fr       */
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
		gettimeofday(&table->tv, NULL);
		now = table->tv.tv_usec;
		while (i < table->number_of_philosophers)
		{
			if((now - table->philo[i].eat_clock_in) >= table->philo[i].time_to_die)
			{
				table->death = 1;
				break ;
			}
			i++;
		}
	}
}

void	philosophers_needs(t_philo *philo)
{
	pthread_mutex_t	*left;
	if(philo->ID % 2 != 0)
		usleep(50000);
	while(42)
	{
		if (philo->ID == 0)
			left = &philo->table->forks[philo->number_of_philosophers - 1];
		else
			left = &philo->table->forks[philo->ID - 1];
		pthread_mutex_lock(&philo->table->forks[philo->ID]);//el primero
		printf("%d: Primer tenedor cogido\n", philo->ID + 1);
		pthread_mutex_lock(left);
		printf("%d: segundo tenedor cogido(el del philo)\n", philo->ID + 1);
		printf("%d: comer: %d\n", philo->ID + 1 ,philo->time_to_eat);
		usleep(philo->time_to_eat * 1000);
		printf("%d: comer FIN\n", philo->ID + 1);
/*coge tiempo*/	god->philo->eat_clock_in = gettimeofday(&tv, NULL);
		pthread_mutex_unlock(&philo->table->forks[philo->ID]);
		printf("%d: Primer tenedor libre\n", philo->ID + 1);
		pthread_mutex_unlock(left);
		printf("%d: Segundo tenedor libre\n", philo->ID + 1);
		printf("%d: A mimir\n", philo->ID + 1);
		usleep(philo->time_to_sleep * 1000);
		printf("%d: Acaba de mimir, ahora a pensar\n", philo->ID + 1);
	}
}
void	creating_threads(t_table *table)
{
	int	i;

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
	while(i < table->number_of_philosophers)
	{
		pthread_create(&table->id[i], NULL, (void *)&philosophers_needs, (void *)&table->philos[i]); // los args pueden ser incorrectos
		i++;
	}
	pthread_create(table->god_id, NULL, (void *)&god_decisions, (void *)table);
	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_join(table->id[i], NULL);
	pthread_join(table->god_id, NULL);
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
