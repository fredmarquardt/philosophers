/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 07:51:26 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/20 13:20:17 by fmarquar         ###   ########.fr       */
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
	table->even_seats = false;
	init_mutex_fork(table->m_fork);
	return (table);
}

void	init_mutex_fork(pthread_mutex_t *m_fork)
{
	int	i;

	i = 0;
	while (i < SEATS)
	{
		pthread_mutex_init(&m_fork[i], NULL);
		printf("Gabel %i Initialisert\n", i);
		i++;
	}
	return ;
}