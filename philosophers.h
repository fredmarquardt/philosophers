/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:02:45 by fmarquar          #+#    #+#             */
/*   Updated: 2023/09/19 16:34:41 by fmarquar         ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1
# define SEATS 9
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4

typedef struct s_table	t_table;

typedef struct s_philos
{
	int				phil_id;
	int				fork_id[2];
	time_t			last_meal;
	pthread_mutex_t	meal_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_table			*table;
}	t_philos;

typedef struct s_table
{
	time_t			start;
	t_philos		philo[SEATS];
	pthread_mutex_t	fork[SEATS];
	pthread_t		p_fred[SEATS];
	pthread_mutex_t	print;
	pthread_mutex_t	dead_lock;
	bool			even_seats;
	bool			dead_philo;
	int				id_counter;
	int				seats_taken;
	int				ttsleep;
	int				tteat;
	int				ttdie;
}	t_table;

//main.c
void		check_health(t_table *table);

//tischlein_deck_dich.c
t_philos	*alloc_philo(void);
t_table		*allocate_table(void);
void		init_mutex_fork(t_table *table);
void		init_mutex_table(t_table *table);

//create_philos.c
void		create_philo_threads(t_table *table);
void		give_fork_pls(t_table *table);

//eat_sleep_repeat.c
void		*cycle(void *arg);
void		eating(t_philos *philo);
void		sleeping(t_philos *philo);
void		thinking(t_philos *philo);
void		grab_fork(t_philos *philo);
void		release_fork(t_philos *philo);

//clean_table.c
void		all_clean(t_table *table);
void		join_threads(t_table *table);
void		destroy_mutex_fork(t_table *table);
void		free_table(t_table *table);

//utils.c
void		print_status(t_philos *philo, int task);
time_t		get_time_stamp(void);
void		do_philo_stuff(int time_in_ms);

#endif