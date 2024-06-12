/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:46:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/12 19:22:05 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_unlock_forks(t_philo *philo, pthread_mutex_t *right,
	pthread_mutex_t *left, int mod)
{
	pthread_mutex_t	*tmp_left;
	pthread_mutex_t	*tmp_right;

	if (philo->id % 2 == 0)
	{
		tmp_left = right;
		tmp_right = left;
	}
	else
	{
		tmp_left = left;
		tmp_right = right;
	}
	if (!mod)
	{
		pthread_mutex_lock(tmp_left);
		lets_print(philo->table, "has take the right fork", philo->id + 1);
		pthread_mutex_lock(tmp_right);
	}
	else
	{
		pthread_mutex_unlock(tmp_left);
		pthread_mutex_unlock(tmp_right);
	}
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
	if (get_int(table->data, &table->death) == 1)
		return ;
	pthread_mutex_lock(table->print);
	printf("%.4lld : %d  %s\n", now - table->start, p, str);
	pthread_mutex_unlock(table->print);
}
