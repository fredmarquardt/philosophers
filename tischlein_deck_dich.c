/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tischlein_deck_dich.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 07:51:26 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/19 14:13:32 by fmarquar         ###   ########.fr       */
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
	table->start = get_time_stamp();
	table->dead_philo = false;
	table->even_seats = false;
	table->seats_taken = SEATS;
	table->tteat = 200;
	table->ttsleep = 200;
	table->ttdie = 2000;
	return (table);
}

void	init_mutex_table(t_table *table)
{
	pthread_mutex_init(&table->print, NULL);
}

void	init_mutex_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->seats_taken)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		pthread_mutex_init(&table->philo[i].meal_time, NULL);
		pthread_mutex_lock(&table->philo[i].meal_time);
		table->philo[i].last_meal = get_time_stamp();
		pthread_mutex_unlock(&table->philo[i].meal_time);
		printf("Gabel %i Initialisert\n", i + 1);
		i++;
	}
	return ;
}
