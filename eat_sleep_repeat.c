/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_repeat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:05:53 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/19 14:20:14 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*cycle(void *arg)
{
	int			i;
	t_philos	*philo;

	philo = arg;
	i = 1;
	while (i < 5)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		i++;
	}
	print_status(philo, DEAD);
	pthread_mutex_lock(&philo->table->dead_lock);
	philo->table->dead_philo = true;
	printf("ENDE DEATH Status:%i\n", philo->table->dead_philo);
	pthread_mutex_lock(&philo->table->dead_lock);
	return (NULL);
}

void	eating(t_philos *philo)
{
	grab_fork(philo);
	print_status(philo, EAT);
	do_philo_stuff(200);
	pthread_mutex_lock(&philo->meal_time);
	philo->last_meal = get_time_stamp();
	pthread_mutex_unlock(&philo->meal_time);
	release_fork(philo);
}

void	sleeping(t_philos *philo)
{
	print_status(philo, SLEEP);
	do_philo_stuff(200);
}

void	thinking(t_philos *philo)
{
	print_status(philo, THINK);
	if (philo->phil_id % 2 == 1)
	{
		while (pthread_mutex_lock(philo->right_fork) != 0)
			do_philo_stuff(1);
		pthread_mutex_unlock(philo->right_fork);
	}
	if (philo->phil_id % 2 == 0)
	{
		while (pthread_mutex_lock(philo->left_fork) != 0)
			do_philo_stuff(1);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	grab_fork(t_philos *philo)
{
	if (philo->phil_id % 2 == 1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, FORK);
	}
	else if (philo->phil_id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
	}
}

void	release_fork(t_philos *philo)
{
	if (philo->phil_id % 2 == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else if (philo->phil_id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}
