/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:40:46 by aduregon          #+#    #+#             */
/*   Updated: 2021/04/19 19:00:16 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_table
{
	int				cont;
	int				turn;
	int				num_philo;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				num_meal;
	int				round;
	u_int64_t	 	now;
	sem_t			*status;
	sem_t			*print;
	sem_t			*dead;
	u_int64_t		start;
	pid_t			father;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				status;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	int				remain_meal;
	t_table			*table;
	pid_t			pid;
}					t_philo;

void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nelem, size_t elsize);
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
void			input_error(void);
u_int64_t		get_time_stamp(void);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
int				parse_input(char **argv, int argc);
t_table			init_table2(char **argv, int argc);
t_table			init_table(char **argv, int argc);
t_philo			*init_philo(t_table table);
void			print_dead(t_philo *philo, unsigned long long t, int i);
void			print_sleep(t_philo *philo, unsigned long long t, int i);
void			print_think(t_philo *philo, unsigned long long t, int i);
void			print_fork(t_philo *philo, unsigned long long t, int i);
void			print_eat(t_philo *philo);
void			start_life(char **argv, t_philo *philo, pthread_t *p, \
							t_table table);
void			ft_sleep(t_philo *philo);
void			philo_eat_odd(t_philo *philo);
void			philo_eat_even(t_philo *philo);
void			philo_eat_last(t_philo *philo);
int				philo_even(t_philo *philo, pthread_t monitor);
int				philo_odd(t_philo *philo, pthread_t monitor);
void			pid_born(t_philo *philo, t_table table);
void			*philosopher(void *input);
void			ft_exit(void);
void			ft_usleep(int t);

#endif