/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:46:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/06/06 19:51:42 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philos(t_table *table, char *str, int p)
{
	pthread_mutex_lock(table->print);
	printf("%s, %d\n", str, p);
	pthread_mutex_unlock(table->print);
}
