/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:01:08 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/20 13:16:47 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//void eating

void	get_start_date(t_table *table)
{
	time_t			sec;
	time_t			micro_sec;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) < 0)
		return ;
	sec = current_time.tv_sec * 1000;
	micro_sec = current_time.tv_usec / 1000;
	table->start = sec + micro_sec;
	printf("TIME: %ld\n", table->start);
	printf("MICROSEC: %ld\n", micro_sec);
	return ;
}

time_t	get_now_date(t_table *table)
{
	time_t			delta;
	time_t			sec;
	time_t			micro_sec;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) < 0)
		return (0);
	sec = current_time.tv_sec * 1000;
	micro_sec = current_time.tv_usec / 1000;
	delta = sec + (micro_sec) - table->start;
	printf("TIME: %ld\n", (sec + micro_sec));
	printf("MICROSEC: %ld\n", micro_sec);
	return (delta);
}

int	main(void)
{
	t_table		*table;
	t_philos	*philos;
	time_t		delta;

	table = allocate_table();
	philos = alloc_philo();
	//create_philo(table);
	get_start_date(table);
	usleep(2000000);
	delta = get_now_date(table);
	for (int i = 0; i < SEATS; i++)
		pthread_mutex_destroy(&(table->m_fork[i]));
	printf("TIME: %ld\n", delta);
	return (0);
}