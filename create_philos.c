/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:12:57 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/28 15:06:52 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	give_fork_pls(t_table *table)
{
	int	i;
	int	s;

	i = 0;
	s = table->seats_taken;
	while (i < s)
	{
		table->philo[i].table = table;
		table->philo[i].phil_id = i + 1;
		table->philo[i].right_fork = &table->fork[i];
		if (i != 0)
			table->philo[i].left_fork = &table->fork[i - 1];
		if (i == 0)
			table->philo[i].left_fork = &table->fork[s - 1];
		i++;
	}
}

void	create_philo_threads(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->seats_taken)
	{
		pthread_create(&table->p_fred[i], NULL, &cycle, &table->philo[i]);
		i++;
	}
}

void	*cycle(void *arg)
{
	int			i;
	t_philos	*philo;
	bool		dead;

	philo = arg;
	i = 1;
	if (philo->table->seats_taken == 1)
	{
		single_philo(philo);
		return (NULL);
	}
	while ((i < philo->table->ms || philo->table->ms == -1) && dead == FALSE)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(&philo->table->dead_lock);
		dead = philo->table->dead_philo;
		pthread_mutex_unlock(&philo->table->dead_lock);
		i++;
	}
	pthread_mutex_lock(&philo->table->dead_lock);
	philo->table->dead_philo = TRUE;
	pthread_mutex_unlock(&philo->table->dead_lock);
	return (NULL);
}

int	a_philo_is_dead(t_philos *philo)
{
	pthread_mutex_lock(&philo->table->dead_lock);
	if (philo->table->dead_philo == TRUE)
	{
		pthread_mutex_unlock(&philo->table->dead_lock);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->table->dead_lock);
	do_philo_stuff(1);
	return (ALIVE);
}
