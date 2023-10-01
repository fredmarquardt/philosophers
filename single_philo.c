/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:52:14 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/28 15:08:02 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	single_philo(t_philos *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	do_philo_stuff(philo->table->ttdie);
	pthread_mutex_unlock(philo->right_fork);
}
