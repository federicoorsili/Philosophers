/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:10:28 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 13:13:38 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	print_fork(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "has taken a fork\n", text);
	pthread_mutex_lock(&(philo->table->print));
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&(philo->table->print));
		return ;
	}
	write(1, text, ft_strlen(text));
	pthread_mutex_unlock(&(philo->table->print));
	free(timestamp);
	free(id);
}

void	print_eat(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is eating\n", text);
	pthread_mutex_lock(&(philo->table->print));
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&(philo->table->print));
		return ;
	}
	write(1, text, ft_strlen(text));
	pthread_mutex_unlock(&(philo->table->print));
	free(timestamp);
	free(id);
}
