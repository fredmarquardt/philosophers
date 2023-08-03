/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tischlein_deck_dich.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 07:51:26 by fmarquar          #+#    #+#             */
/*   Updated: 2023/08/03 17:22:18 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philos	*alloc_philo(void)
{
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos));
	if (philos == NULL)
		return (NULL);
	return (philos);
}

t_table	*allocate_table(void)
{
	t_table		*table;
	int			i;

	i = 0;
	table = (t_table *)malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	table->start = 0;
	table->dead_philo = false;
	table->even_seats = false;
	table->seats_taken = 10;
	table->tteat = 200;
	table->ttsleep = 200;
	table->ttdie = 500;
	return (table);
}

void	init_mutex_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->seats_taken)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		pthread_mutex_init(&table->philo[i].meal_time, NULL);
		printf("Gabel %i Initialisert\n", i + 1);
		i++;
	}
	return ;
}
