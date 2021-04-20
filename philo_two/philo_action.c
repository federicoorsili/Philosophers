/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:55:51 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 18:45:00 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	take_first_fork(t_philo *philo)
{
	sem_wait((philo->table->status));
	print_fork(philo, get_time_stamp() - \
			philo->table->start, philo->id);
	sem_wait((philo->table->dead));
	print_eat(philo, get_time_stamp() - \
			philo->table->start, philo->id);
	sem_post((philo->table->dead));
	philo->remain_meal++;
	sem_post((philo->table->status));
}

void	philo_eat(t_philo *philo)
{
	sem_wait((philo->table->status));
	print_fork(philo, get_time_stamp() - \
				philo->table->start, philo->id);
	print_fork(philo, get_time_stamp() - \
		philo->table->start, philo->id);
	sem_wait((philo->table->dead));
	print_eat(philo, get_time_stamp() - \
		philo->table->start, philo->id);
	sem_post((philo->table->dead));
	philo->remain_meal++;
	ft_usleep((float)philo->table->time_to_eat);
	sem_post((philo->table->status));
	philo->eat_time = get_time_stamp();
}

void	philo_sleep(t_philo *philo)
{
	print_sleep(philo, get_time_stamp() - \
				philo->table->start, philo->id);
	ft_usleep((float)philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_think(philo, get_time_stamp() - \
						philo->table->start, philo->id);
}

void	wait_turn(t_philo *philo)
{
	if (philo->id % 2 == 1)
		ft_usleep((float)philo->table->time_to_eat);
	if (philo->table->num_philo % 2 == 1 && \
		philo->id == philo->table->num_philo - 1)
		ft_usleep(((float)philo->table->time_to_eat) * 1.5);
}
