#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

typedef struct  s_philo
{
    int                 id;
    int                 n_philo;
    int                 time_to_die;
    int                 time_to_eat;
    int                 time_to_sleep;
    int                 min_eat;
    pthread_mutex_t     *mutex;
}               t_philo;



void			*ft_memset(void *s, int c, size_t n);
void		    *ft_calloc(size_t nelem, size_t elsize);
int			    ft_isspace(int c);
int			    ft_isdigit(int c);
int				ft_atoi(const char *nptr);

#endif