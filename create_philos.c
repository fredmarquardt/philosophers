/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:12:57 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/19 16:50:46 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philos	*philos;
	int			i;

	i = 0;
	philos = (t_philos *)arg;
	while (i < 2)
	{
		pthread_mutex_lock(&philos->m_fork[i]);
		pthread_mutex_lock(&philos->m_fork[i + 1]);
		printf("Mahlzeit P%i\n", i);
		usleep(500000);
		pthread_mutex_unlock(&philos->m_fork[i]);
		pthread_mutex_unlock(&philos->m_fork[i + 1]);
		i++;
	}
	return (NULL);
}

void	create_philo(t_philos *philos)
{
	pthread_t	p1;
	pthread_t	p2;

	pthread_mutex_init(&philos->m_fork[0], NULL);
	pthread_create(&p1, NULL, &routine, &philos);
	pthread_create(&p2, NULL, &routine, &philos);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_mutex_destroy(&philos->m_fork[0]);
}
