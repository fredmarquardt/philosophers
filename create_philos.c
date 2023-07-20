/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:12:57 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/20 09:56:32 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_table	*table;
	int			i;

	i = 0;
	table = (t_table *)arg;
	while (i < 2)
	{
		pthread_mutex_lock(&table->m_fork[i]);
		pthread_mutex_lock(&table->m_fork[i + 1]);
		printf("Mahlzeit P%i\n", i);
		usleep(500000);
		pthread_mutex_unlock(&table->m_fork[i]);
		pthread_mutex_unlock(&table->m_fork[i + 1]);
		i++;
	}
	return (NULL);
}

void	create_philo(t_table *table)
{
	pthread_t	p1;
	pthread_t	p2;

	pthread_mutex_init(&table->m_fork[0], NULL);
	pthread_create(&p1, NULL, &routine, &table);
	pthread_create(&p2, NULL, &routine, &table);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_mutex_destroy(&table->m_fork[0]);
}
