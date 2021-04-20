/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:10:28 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 18:48:46 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	print_fork(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	sem_wait((philo->table->print));
	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "has taken a fork\n", text);
	if (philo->table->is_dead)
	{
		free(timestamp);
		free(id);
		sem_post((philo->table->print));
		return ;
	}
	write(1, text, ft_strlen(text));
	free(timestamp);
	free(id);
	sem_post((philo->table->print));
}

void	print_eat(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	sem_wait((philo->table->print));
	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is eating\n", text);
	if (philo->table->is_dead)
	{
		free(timestamp);
		free(id);
		sem_post((philo->table->print));
		return ;
	}
	write(1, text, ft_strlen(text));
	free(timestamp);
	free(id);
	sem_post((philo->table->print));
}
