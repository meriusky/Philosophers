/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:18:18 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/01 19:32:20 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> //substituir per el meu printf
#include "printf.h"
#include <pthread.h>
#include "philo.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	num;
	int	sign;

	count = 0;
	num = 0;
	sign = 1;
	while (str[count] == '\t' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = (num * 10) + (str[count] - '0');
		count++;
	}
	return (num * sign);
}

int	check_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
		{
			printf("Just numbers accepted\n");
			return (-1); //quizas hay que poner error especifico
		}	
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int i;
	t_table	table;
	t_philo *arr;

	i = 0;
	if (argc == 5)
	{
		if (check_num(argv[1]) == -1 || check_num(argv[2]) == -1
			|| check_num(argv[3]) == -1 || check_num(argv[4] == -1))
			return (0);
		arr = ft_calloc(i + 1, sizeof(t_philo));
		if(table.fork < 2)
		{
			printf("there is not enought philosophers🦉\n");
			return (1); //quizas hay que poner error especifico
		}
		while(i != ft_atoi(argv[1]))
		{
			arr[i].ID = i;
			arr[i].time_to_die = ft_atoi(argv[2]);
			arr[i].time_to_sleep = ft_atoi(argv[3]);
			arr[i].time_to_eat = ft_atoi(argv[4]);
			arr[i].last_eaten = 0;
			arr[i].table = &table;
			i++;
		}
		arr[i] = NULL;
		table.philos = arr;
		creating_threads(&table);
	}
	else
		printf("Just 4 arguments permited🦉\n");
	return(0);
}

/*🎀BENVINGUDA AL MAIN🎀
 * 1. Els arguments variaran entre 4 i 5
 * 		1.1number_of_philosophers
 * 		1.2time_to_die -> si el time to die llega y el filosofo no ha comido...💀
 * 		1.3time_to_sleep -> tiempo que un filosofo duerme
 * 		1.4time_to_eat -> tiempe que un filosofo que tarda en comer un filosofo
 * 		1.5number_of_times_each_philosopher_must_eat
 * 2. Funcio per pasar de caracter a int, molt important ppel temps
 * 3.Potser no cal diferenciar entre els arguments amb el opcional o sense, pero dmeoment els separo
 *
 * */

