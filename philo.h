/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:27:15 by mehernan          #+#    #+#             */
/*   Updated: 2024/05/29 17:03:33 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo.h"

typedef struct s_philo
{
	int		time_to_die;
	int		time_to_sleep;
	int		time_to_eat;
	int		number_of_philosophers;
} t_philo;


#endif
