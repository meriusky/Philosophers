/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:20:14 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/13 16:35:01 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_int(t_mutex *mutex, int *value, int new)
{
	pthread_mutex_lock(mutex);
	*value = new;
	pthread_mutex_unlock(mutex);
}

void	set_long(t_mutex *mutex, long long *value, long long new)
{
	pthread_mutex_lock(mutex);
	*value = new;
	pthread_mutex_unlock(mutex);
}

long long	get_long(t_mutex *mutex, long long *value)
{
	long long	tmp;

	pthread_mutex_lock(mutex);
	tmp = *value;
	pthread_mutex_unlock(mutex);
	return (tmp);
}

int	get_int(t_mutex *mutex, int *value)
{
	int	tmp;

	pthread_mutex_lock(mutex);
	tmp = *value;
	pthread_mutex_unlock(mutex);
	return (tmp);
}
