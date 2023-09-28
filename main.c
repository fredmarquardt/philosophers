/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:01:08 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/27 16:07:06 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_table		*table;
	bool		dead;

	dead = FALSE;
	if (correct_args(argc, argv) == FALSE)
		return (0);
	table = allocate_table(argc, argv);
	init_mutex_table(table);
	init_mutex_fork(table);
	give_fork_pls(table);
	create_philo_threads(table);
	while (dead == FALSE)
	{
		check_health(table);
		pthread_mutex_lock(&table->dead_lock);
		dead = table->dead_philo;
		pthread_mutex_unlock(&table->dead_lock);
		do_philo_stuff(1);
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
	while (i < table->seats_taken) // && table->dead_philo == FALSE)
	{
		pthread_mutex_lock(&table->philo[i].meal_time);
		hungry = get_time_stamp() - table->philo[i].last_meal;
		pthread_mutex_unlock(&table->philo[i].meal_time);
		if (hungry > table->ttdie)
		{
			print_status(&table->philo[i], DEAD);
			pthread_mutex_lock(&table->dead_lock);
			printf("Status %p\n", &table->dead_lock);
			table->dead_philo = TRUE;
			pthread_mutex_unlock(&table->dead_lock);
		}
		i++;
	}
}