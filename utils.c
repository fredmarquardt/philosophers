/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:21:50 by fmarquar          #+#    #+#             */
/*   Updated: 2023/08/02 12:51:09 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philos *philo, int task)
{
	time_t		time_stamp;

	time_stamp = get_time_stamp();
	if (task == FORK)
		printf("%ld %i has taken a fork\n", time_stamp, philo->phil_id);
	if (task == EAT)
		printf("%ld %i is eating\n", time_stamp, philo->phil_id);
	if (task == SLEEP)
		printf("%ld %i is sleeping\n", time_stamp, philo->phil_id);
	if (task == THINK)
		printf("%ld %i is thinking\n", time_stamp, philo->phil_id);
	if (task == DEAD)
		printf("%ld %i died\n", time_stamp, philo->phil_id);
}

time_t	get_time_stamp(void)
{
	time_t			sec;
	time_t			micro_sec;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) < 0)
		return (0);
	sec = current_time.tv_sec * 1000;
	micro_sec = current_time.tv_usec / 1000;
	return (sec + micro_sec);
}

void	do_philo_stuff(int time_in_ms)
{
	usleep(time_in_ms * 1000);
}

/* void	get_start_date(t_table *table)
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
} */