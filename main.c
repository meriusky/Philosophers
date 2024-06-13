/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:18:18 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/13 16:56:47 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str, int out)
{
	printf("%s", str);
	return (out);
}

int	free_func(t_table *table, char *str, int out)
{
	if (table->id)
		free(table->id);
	if (table->data)
		free(table->data);
	if (table->forks)
		free(table->forks);
	if (table->print)
		free(table->print);
	if (table->god_id)
		free(table->god_id);
	if (table->philos)
		free(table->philos);
	if (out != 0)
		return (error(str, out));
	return (0);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
			return (error("Just number accepted\n", -1));
	}
	return (0);
}

static int	get_array(t_philo *arr, t_table *table, char **argv, int i)
{
	while (i < ft_atoi(argv[1]))
	{
		arr[i].id = i;
		arr[i].time_to_eat = ft_atoi(argv[3]);
		arr[i].time_to_sleep = ft_atoi(argv[4]);
		arr[i].eat_clock_in = 0;
		arr[i].number_of_philosophers = ft_atoi(argv[1]);
		arr[i].table = table;
		arr[i].eat_times = 0;
		if (argv[5] != NULL && check_num(argv[5]) == 0)
			arr[i].must_eat = ft_atoi(argv[5]);
		else
			arr[i].must_eat = -1;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_philo	*arr;
	t_table	table;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (check_num(argv[1]) == -1 || check_num(argv[2]) == -1
			|| check_num(argv[3]) == -1 || check_num(argv[4]) == -1)
			return (1);
		arr = (t_philo *)ft_calloc(ft_atoi(argv[1]), sizeof(t_philo));
		if (!arr)
			return (error("Malloc error\n", 1));
		if (get_array(arr, &table, argv, i) == 1)
			return (1);
		set_values(&table, arr, argv);
		if (creating_threads(&table) == 1)
			return (1);
		return (free_func(&table, "", 0));
	}
	else
		printf("Just 5 and 6 arguments permitted🦉\n");
	return (0);
}
