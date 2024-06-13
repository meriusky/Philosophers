/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:13:21 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/13 16:33:23 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_values(t_table *table, t_philo *arr, char **argv)
{
	table->philos = arr;
	table->time_to_die = ft_atoi(argv[2]);
	if (argv[5] != NULL && check_num(argv[5]) == 0)
		table->must_eat = ft_atoi(argv[5]);
	else
		table->must_eat = -1;
	table->number_of_philosophers = ft_atoi(argv[1]);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*dst;

	dst = (char *)s;
	count = 0;
	while (count < n)
	{
		dst[count] = 0;
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}

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
