/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:18:18 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/10 19:52:33 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
		{
			printf("Just numbers accepted\n");
			return (-1);
		}
	}
	return (0);
}

void	get_array(t_philo *arr, t_table *table, char argv[], int i)
{
	if (check_num(argv[1]) == -1 || check_num(argv[2]) == -1
		|| check_num(argv[3]) == -1 || check_num(argv[4]) == -1)
		return (0);
	arr = (t_philo *)ft_calloc(ft_atoi(argv[1]), sizeof(t_philo));
	if (ft_atoi(argv[1]) < 2)
	{
		printf("there is not enought philosophers🦉\n");
		return (1);
	}
	while (i < ft_atoi(argv[1]))
	{
		arr->ID = i;
		arr->time_to_die = ft_atoi(argv[2]);
		arr->time_to_sleep = ft_atoi(argv[3]);
		arr->time_to_eat = ft_atoi(argv[4]);
		arr->eat_clock_in = 0;
		arr->number_of_philosophers = ft_atoi(argv[1]);
		arr->table = &table;
		arr->eat_times = 0;
		if (argv[5] != NULL && check_num(argv[5]) == 0)
			arr->must_eat = ft_atoi(argv[5]);
		else
			arr->must_eat = -1;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	t_table	table;
	t_philo	*arr;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		get_array(&arr[i], &table, argv[], i);
		table.number_of_philosophers = ft_atoi(argv[1]);
		table.philos = arr;
		creating_threads(&table);
	}
	else
		printf("Just 4 arguments permited🦉\n");
	return (0);
}
