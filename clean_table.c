/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:45:13 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/28 14:56:43 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	all_clean(t_table *table)
{
	join_threads(table);
	destroy_mutex_fork(table);
	free_table(table);
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->seats_taken)
	{
		pthread_join(table->p_fred[i], NULL);
		i++;
	}
	return ;
}

void	destroy_mutex_fork(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->seats_taken)
	{
		pthread_mutex_destroy(&table->fork[i]);
		i++;
	}
	return ;
}

void	free_table(t_table *table)
{
	if (table != NULL)
		free (table);
}
