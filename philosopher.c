#include "philosopher.h"

void	take_info(int info[5], char **argv)
{
	info[1] = ft_atoi(argv[2]);
	if (info[1] <= 0)
		exit(0); 
	info[2] = ft_atoi(argv[3]);
	if (info[2] <= 0)
		exit(0); 
	info[3] = ft_atoi(argv[4]);
	if (info[3] <= 0)
		exit(0);
	if (argv[5])
	{
		info[4] = ft_atoi(argv[5]);
		if (info[4] <= 0)
			exit(0); 
	}
	else
		info[4] = -1;
}

t_philo	*put_infop(t_philo *infop, int info[5], pthread_mutex_t *mutex)
{
	int i;

	i = 0;
	while (i < info[0])
	{
		infop[i].id = i;
		infop[i].n_philo = info[0];
		infop[i].time_to_die = info[1];
		infop[i].time_to_eat = info[2];
		infop[i].time_to_sleep = info[3];
		infop[i].min_eat = info[4];
		infop[i].mutex = mutex;
		i++;
	}
	return (infop);
}

t_philo	*parse(char **argv, int argc, pthread_mutex_t *mutex)
{
    t_philo     *infop;
	int			info[5];

	info[0] = ft_atoi(argv[1]);
	if (info[0] < 2)
		exit(0);
	infop = ft_calloc(sizeof(t_philo), info[0] + 1);
	take_info(info, argv);
	infop = put_infop(infop, info, mutex);
	return (infop);
}

void	*print(void *input)
{
	t_philo *infop;
	int		i;

	infop = (t_philo *)input;
	pthread_mutex_lock(infop->mutex);
	printf("ID: %d", infop->id);
	printf("\n");
	pthread_mutex_unlock(infop->mutex);
	return (0);
}

void	make_thread(t_philo *infop)
{
	pthread_t	*p;
	int			i;
	int			k;
	
	i = 0;
	p = ft_calloc(infop[0].n_philo, sizeof(pthread_t));
	while (i < infop[0].n_philo)
	{
		pthread_create(&p[i], NULL, &print, (void *)&infop[i]);
		i++;
	}
	k = 0;
	while (k < infop[0].n_philo)
	{
		pthread_join(p[k], NULL);
		k++;
	}
}

void	philosopher(char **argv, int argc)
{
    t_philo     *infop;
	pthread_mutex_t	mutex;
    pthread_t   *p;

	pthread_mutex_init(&mutex, NULL);
    infop = parse(argv, argc, &mutex);
	int i=0;
	make_thread(infop);	
}

int	main(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        exit(0);
    philosopher(argv, argc);
    return (0);
}