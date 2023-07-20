/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:02:45 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/20 14:00:53 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# define FALSE 0
# define TRUE 1
# define SEATS 200

typedef struct s_philos
{
	int				phil_id;
	int				fork_id[2];
}	t_philos;

typedef struct s_table
{
	time_t			start;
	t_philos		philo[SEATS];
	pthread_mutex_t	m_fork[SEATS];
	bool			even_seats;
	int				seats_taken;
}	t_table;

//allocate_free.c
t_philos	*alloc_philo(void);
t_table		*allocate_table(void);
void		init_mutex_fork(pthread_mutex_t *m_fork);

//create_philos.c
void		create_philo(t_table *table);
void		*routine(void *arg);

#endif