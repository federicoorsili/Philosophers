/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:17:37 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 18:49:58 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*is_dead(void *input)
{
	t_philo		*philo;

	philo = (t_philo *)input;
	while (1)
	{
		if (philo->status == 1)
			return (NULL);
		sem_wait((philo->table->dead));
		if (get_time_stamp() - philo->eat_time > philo->table->time_to_die && \
			philo->table->time_to_eat != 0 && philo->table->time_to_sleep != 0)
		{
			print_dead(philo, get_time_stamp() - \
						philo->table->start, philo->id);
			philo->table->is_dead = 1;
			sem_post((philo->table->dead));
			return (NULL);
		}
		sem_post((philo->table->dead));
	}
	return (NULL);
}

void	*philosopher(void *input)
{
	t_philo		*philo;
	pthread_t	monitor;

	philo = (t_philo *)input;
	philo->remain_meal = 0;
	philo->eat_time = get_time_stamp();
	pthread_create(&monitor, NULL, &is_dead, &(*input));
	wait_turn(philo);
	while (1)
	{
		if (!philo->table->is_dead && (philo->remain_meal < \
		philo->table->num_meal || philo->table->num_meal == -1))
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		else
		{
			philo->status = 1;
			pthread_detach(monitor);
			return (NULL);
		}
	}
	return (0);
}

void	start_life(t_philo *philo, pthread_t *p, t_table table)
{
	int	i;

	i = 0;
	while (i < table.num_philo)
	{
		if (table.num_philo % 2 == 1 && i == table.num_philo - 1)
			break ;
		pthread_create(&p[i], NULL, &philosopher, (void *)&philo[i]);
		i += 2;
	}
	i = 1;
	while (i < table.num_philo)
	{
		pthread_create(&p[i], NULL, &philosopher, (void *)&philo[i]);
		i += 2;
	}
	if (table.num_philo % 2 == 1)
		pthread_create(&p[table.num_philo - 1], NULL, &philosopher,
			(void *)&philo[table.num_philo - 1]);
	i = 0;
	while (i < table.num_philo)
	{
		pthread_join(p[i], NULL);
		pthread_detach(p[i++]);
	}
}
