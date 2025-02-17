/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 15:56:35 by pdro              #+#    #+#             */
/*   Updated: 2025-02-15 15:56:35 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

struct s_philo;
typedef struct s_philo t_philo;

struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				last_meal;
	int				nb_meal;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				is_dead;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	t_philo			*next;
	t_philo			*prev;
};

int	init_philo(t_philo *philo, int argc, char **argv);
#endif
