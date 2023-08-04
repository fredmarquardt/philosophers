/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:01:08 by fmarquar          #+#    #+#             */
/*   Updated: 2023/08/04 10:42:43 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(void)
{
	t_table		*table;
	t_philos	*philos;
	bool		dead;

	dead = FALSE;
	table = allocate_table();
	philos = alloc_philo();
	init_mutex_fork(table);
	give_fork_pls(table);
	create_philo_threads(table);
	while (dead == FALSE)
	{
		printf("DEAD LOOP\n");
		pthread_mutex_lock(&table->dead_lock);
		check_health(table);
		dead = table->dead_philo;
		printf("DEATH Status Main:%i\n", table->dead_philo);
		pthread_mutex_unlock(&table->dead_lock);
	}
	all_clean(table);
	return (0);
}

void	check_health(t_table *table)
{
	int		i;
	time_t	hungry;

	i = 0;
	hungry = 0;
	while (i < table->seats_taken && table->dead_philo == FALSE)
	{
		pthread_mutex_lock(&table->philo[i].meal_time);
		hungry = table->philo[i].last_meal - get_time_stamp();
		pthread_mutex_unlock(&table->philo[i].meal_time);
		if (hungry > table->ttdie)
		{
			table->dead_philo = TRUE;
		}
		i++;
	}
}