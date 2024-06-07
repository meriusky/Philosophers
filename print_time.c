/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:46:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/07 17:38:54 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lets_print(t_table *table, char *str, int p)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(table->print);
	printf("%.4lld : %d  %s\n", now - table->start, p, str);
	pthread_mutex_unlock(table->print);
}
