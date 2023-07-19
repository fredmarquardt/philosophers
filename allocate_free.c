/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 07:51:26 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/19 15:49:29 by fmarquar         ###   ########.fr       */
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

	table = (t_table *)malloc(sizeof(t_table));
	if (table != NULL)
	{
		table->start = 0;
		table->even_seats = false;
	}
	return (table);
}
