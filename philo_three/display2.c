/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:24:23 by forsili           #+#    #+#             */
/*   Updated: 2021/04/19 17:20:48 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	print_think(t_philo *philo, unsigned long long t, int i)
{
	sem_wait(philo->table->print);
	printf("%llu %d is thinking\n", t, i);
	sem_post(philo->table->print);
}

void	print_fork(t_philo *philo, unsigned long long t, int i)
{
	sem_wait(philo->table->print);
	printf("%llu %d is taken a fork\n", t, i);
	printf("%llu %d is taken a fork\n", t, i);
	printf("%llu %d is eating\n", t, i);
	sem_post(philo->table->print);
}

void	print_eat(t_philo *philo)
{
	sem_wait(philo->table->print);
	sem_post(philo->table->print);
}
