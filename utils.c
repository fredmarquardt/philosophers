/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:21:50 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/28 15:02:27 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philos *philo, int task)
{
	time_t		time_stamp;
	time_t		time_diff;

	pthread_mutex_lock(&philo->table->dead_lock);
	if (philo->table->dead_philo == TRUE)
	{
		pthread_mutex_unlock(&philo->table->dead_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->table->dead_lock);
	time_stamp = get_time_stamp();
	time_diff = time_stamp - philo->table->start;
	pthread_mutex_lock(&philo->table->print);
	if (task == FORK)
		printf("%ld %i has taken a fork\n", time_diff, philo->phil_id);
	if (task == EAT)
		printf("%ld %i is eating\n", time_diff, philo->phil_id);
	if (task == SLEEP)
		printf("%ld %i is sleeping\n", time_diff, philo->phil_id);
	if (task == THINK)
		printf("%ld %i is thinking\n", time_diff, philo->phil_id);
	if (task == DEAD)
		printf("%ld %i died\n", time_diff, philo->phil_id);
	pthread_mutex_unlock(&philo->table->print);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	res = sign * res;
	return (res);
}

size_t	ft_isaldigit(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	do_philo_stuff(int time_in_ms)
{
	usleep(time_in_ms * 1000);
}
