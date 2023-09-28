/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tischlein_deck_dich.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 07:51:26 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/28 13:35:17 by fmarquar         ###   ########.fr       */
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

t_table	*allocate_table(int argc, char *argv[])
{
	t_table		*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	table->start = get_time_stamp();
	table->dead_philo = false;
	table->even_seats = false;
	table->seats_taken = ft_atoi(argv[1]);
	table->tteat = ft_atoi(argv[3]);
	table->ttsleep = ft_atoi(argv[4]);
	table->ttdie = ft_atoi(argv[2]);
	table->ms = -1;
	if (argc == 6)
		table->ms = ft_atoi(argv[5]);
	return (table);
}

void	init_mutex_table(t_table *table)
{
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
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
		i++;
	}
	return ;
}
