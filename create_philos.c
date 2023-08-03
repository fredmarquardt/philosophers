/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:12:57 by fmarquar          #+#    #+#             */
/*   Updated: 2023/08/03 11:01:10 by fmarquar         ###   ########.fr       */
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
		table->philo[i].left_fork = &table->fork[i - 1];
		if (i == 0)
			table->philo[i].left_fork = &table->fork[s - 1];
		if (i == s - 1)
		{
			table->philo[i].right_fork = &table->fork[0];
			printf("last Fork taken\n");
		}
		printf("PHILO ID: %i\n", table->philo[i].phil_id);
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
