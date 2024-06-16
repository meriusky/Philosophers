/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:46:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/16 17:05:51 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_left_right(t_mutex **tmp_right, t_mutex **tmp_left,
	t_mutex *right, t_mutex *left)
{
	*tmp_left = left;
	*tmp_right = right;
}

int	lock_unlock_forks(t_philo *philo, t_mutex *right,
	t_mutex *left, int mod)
{
	t_mutex	*tmp_left;
	t_mutex	*tmp_right;

	if (philo->id % 2 == 0)
		take_left_right(&tmp_right, &tmp_left, left, right);
	else
		take_left_right(&tmp_right, &tmp_left, right, left);
	if (!mod)
	{
		pthread_mutex_lock(tmp_left);
		lets_print(philo->table, "has take the right fork🍴", philo->id + 1);
		if (philo->number_of_philosophers == 1)
		{
			pthread_mutex_unlock(tmp_left);
			return (1);
		}
		pthread_mutex_lock(tmp_right);
	}
	else
	{
		pthread_mutex_unlock(tmp_left);
		pthread_mutex_unlock(tmp_right);
	}
	return (0);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	my_sleep(long long wait)
{
	wait += get_time();
	while (wait >= get_time())
		usleep (100);
}

void	lets_print(t_table *table, char *str, int p)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(table->print);
	if (get_int(table->data, &table->death) == 1)
	{
		pthread_mutex_unlock(table->print);
		return ;
	}
	printf("%.4lld : %d  %s\n", now - table->start, p, str);
	pthread_mutex_unlock(table->print);
}
