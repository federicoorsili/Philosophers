/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:15:02 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 16:33:30 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
	char	*timestamp;
	char	*id;
	char	text[1000];

	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is dead\n", text);
	pthread_mutex_lock(&(philo->table->print));
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&(philo->table->print));
		free(timestamp);
		free(id);
		return ;
	}
	write(1, text, ft_strlen(text));
	pthread_mutex_unlock(&(philo->table->print));
	free(timestamp);
	free(id);
}

void	print_sleep(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is sleeping\n", text);
	pthread_mutex_lock(&(philo->table->print));
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&(philo->table->print));
		free(timestamp);
		free(id);
		return ;
	}
	write(1, text, ft_strlen(text));
	pthread_mutex_unlock(&(philo->table->print));
	free(timestamp);
	free(id);
}

void	print_think(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is thinking\n", text);
	pthread_mutex_lock(&(philo->table->print));
	if (philo->table->is_dead)
	{
		pthread_mutex_unlock(&(philo->table->print));
		free(timestamp);
		free(id);
		return ;
	}
	write(1, text, ft_strlen(text));
	pthread_mutex_unlock(&(philo->table->print));
	free(timestamp);
	free(id);
}
