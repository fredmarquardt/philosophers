/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:20:41 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/21 14:00:07 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	correct_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments!\n");
		return (FALSE);
	}
	while (i < argc)
	{
		if (correct_input(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	correct_input(const char *arg)
{
	if (ft_isaldigit(arg) == TRUE && ft_strlen(arg) <= 9
		&& ft_atoi(arg) >= 1)
		return (TRUE);
	printf("Wrong input\n Required Information:\n");
	printf("number_of_philosophers\n");
	printf("time_to_die time_to_eat\n");
	printf("time_to_sleep\n");
	printf("Optional: number_of_times_each_philosopher_must_eat\n");
	return (FALSE);
}
