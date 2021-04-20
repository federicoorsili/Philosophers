/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:15:02 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 18:48:25 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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

	sem_wait((philo->table->print));
	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is dead\n", text);
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

void	print_sleep(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	sem_wait((philo->table->print));
	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is sleeping\n", text);
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

void	print_think(t_philo *philo, unsigned long long t, int i)
{
	char	*timestamp;
	char	*id;
	char	text[1000];

	sem_wait((philo->table->print));
	timestamp = ft_itoa(t);
	id = ft_itoa(i);
	stringer(timestamp, id, "is thinking\n", text);
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
