/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:02:45 by fmarquar          #+#    #+#             */
/*   Updated: 2023/07/19 16:45:01 by fmarquar         ###   ########.fr       */
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
	int				id;
	int				phil_id[SEATS];
	int				fork_id[SEATS];
	pthread_mutex_t	m_fork[SEATS];
}	t_philos;

typedef struct s_table
{
	time_t		start;
	bool		even_seats;
}	t_table;

//allocate_free.c
t_philos	*alloc_philo(void);
t_table		*allocate_table(void);

//create_philos.c
void		create_philo(t_philos *philos);
void		*routine(void *arg);

#endif