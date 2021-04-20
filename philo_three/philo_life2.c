/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <forsili@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:17:37 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 14:45:01 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	pid_born(t_philo *philo, t_table table)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < table.num_philo)
	{
		philo->pid = fork();
		if (philo->pid == 0)
		{
			philosopher((void *)&philo[i]);
			exit(0);
		}
		else
			i += 1;
	}
	k = 0;
	while (k < table.num_philo)
	{
		waitpid(philo[k].pid, NULL, 0);
		k++;
	}
	exit(0);
}
