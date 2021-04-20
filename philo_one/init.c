/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:11:23 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 17:53:57 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	parse_input(char **argv, int argc)
{
	if (ft_atoi(argv[1]) < 1)
		return (0);
	if (ft_atoi(argv[2]) < 0)
		return (0);
	if (ft_atoi(argv[3]) < 0)
		return (0);
	if (ft_atoi(argv[4]) < 0)
		return (0);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (0);
	return (1);
}

t_table	init_table2(char **argv, int argc)
{
	t_table	table;

	table.is_dead = 0;
	table.num_philo = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table.num_meal = ft_atoi(argv[5]);
	else
		table.num_meal = -1;
	return (table);
}

t_table	init_table(char **argv, int argc)
{
	t_table			table;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	int				i;

	table = init_table2(argv, argc);
	table.start = get_time_stamp();
	table.fork = ft_calloc(table.num_philo, sizeof(pthread_mutex_t));
	i = 0;
	while (i < table.num_philo)
	{
		pthread_mutex_init(&table.fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&print, NULL);
	pthread_mutex_init(&dead, NULL);
	table.print = print;
	table.dead = dead;
	if (table.time_to_eat == 0 && table.time_to_sleep == 0)
		table.time_to_eat = 1001;
	return (table);
}

t_philo	*init_philo(t_table table)
{
	t_philo	*philo;
	int		i;

	philo = ft_calloc(table.num_philo, sizeof(t_philo));
	i = 0;
	while (i < table.num_philo)
	{
		philo[i].id = i;
		philo[i].status = 0;
		philo[i].remain_meal = 0;
		philo[i].table = &table;
		i++;
	}
	return (philo);
}
