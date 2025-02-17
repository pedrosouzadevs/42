/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 15:56:09 by pdro              #+#    #+#             */
/*   Updated: 2025-02-15 15:56:09 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_philo(t_philo *philo, int argc, char **argv)
{
	int	i;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;

	i = 0;
	while (i < atoi(argv[1]))
	{
		philo[i].id = i + 1;
		philo[i].left_fork = left_fork;
		philo[i].right_fork = right_fork;
		philo[i].last_meal = 0;
		philo[i].nb_meal = 0;
		philo[i].is_eating = 0;
		philo[i].is_sleeping = 0;
		philo[i].is_thinking = 0;
		philo[i].is_dead = 0;
		philo[i].nb_philo = atoi(argv[1]);
		philo[i].time_to_die = atoi(argv[2]);
		philo[i].time_to_eat = atoi(argv[3]);
		philo[i].time_to_sleep = atoi(argv[4]);
		if (argc == 6)
			philo[i].nb_must_eat = atoi(argv[5]);
		else
			philo[i].nb_must_eat = -1;
		if (i == philo[i].nb_philo - 1)
			philo[i].next = &philo[0];
		else
			philo[i].next = &philo[i + 1];
		if (i == 0)
			philo[i].prev = &philo[philo[i].nb_philo - 1];
		else
			philo[i].prev = &philo[i - 1];
		i++;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * atoi(argv[1]));
	if (!philo)
		return (1);
	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (init_philo(philo, argc, argv))
	{
		printf("Error: failed to initialize philo\n");
		return (1);
	}
	// if (start_simulation(philo))
	// {
	// 	printf("Error: failed to start simulation\n");
	// 	return (1);
	// }
	for (int i = 0; i < philo[0].nb_philo; i++)
    {
        printf("Filósofo %d criado com ID %d\n", i + 1, philo[i].id);
		printf("Filósofo anterior %d\n", philo[i].prev->id);
		printf("Filósofo seguinte %d\n", philo[i].next->id);

    }
	return (0);
}
