/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:15:02 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 19:02:20 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	stringer(char *timestamp, char *id, char *phrase, char final[1000])
{
	while (*timestamp)
		*final++ = *timestamp++;
	*final++ = ' ';
	while (*id)
		*final++ = *id++;
	*final++ = ' ';
	while (*phrase)
		*final++ = *phrase++;
	*final = 0;
}

void	print_dead(t_philo *philo, unsigned long long t, int i)
{
	sem_wait(philo->table->print);
	printf("%llu %d is dead\n", t, i);
	sem_post(philo->table->print);
}

void	print_sleep(t_philo *philo, unsigned long long t, int i)
{
	sem_wait(philo->table->print);
	printf("%llu %d is sleeping\n", t, i);
	sem_post(philo->table->print);
	ft_usleep((float)philo->table->time_to_sleep);
}
