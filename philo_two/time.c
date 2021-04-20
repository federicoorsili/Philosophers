/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:26:29 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 15:49:07 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

u_int64_t	get_time_stamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	ft_usleep(int t)
{
	unsigned long long	time;

	time = get_time_stamp();
	while (get_time_stamp() < time + t)
		usleep(t);
}
