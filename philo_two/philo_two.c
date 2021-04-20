/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:20:26 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 17:11:50 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_alone(t_table table)
{
	printf("0 0 has taken a fork\n");
	usleep(table.time_to_die * 1000);
	printf("%llu 0 is dead\n", table.time_to_die);
}

int	main(int argc, char **argv)
{
	t_table		table;
	t_philo		*philo;
	pthread_t	*p;

	if (argc < 5 || argc > 6)
		input_error();
	if (!parse_input(argv, argc))
		input_error();
	p = ft_calloc(ft_atoi(argv[1]), sizeof(pthread_t));
	table = init_table(argv, argc);
	philo = init_philo(table);
	if (philo->table->num_philo == 1)
		ft_alone(table);
	else
		start_life(philo, p, table);
	free(philo);
	free(p);
}
