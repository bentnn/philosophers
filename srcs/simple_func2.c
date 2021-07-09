#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (error_with_message("Error: wrong number of arguments\n", 0));
	i = 1;
	while (i < argc)
	{
		if (!is_pos_int(argv[i]) || ft_strlen(argv[i]) > 10
			|| ft_atoi(argv[i]) < 1)
			return (error_with_message("Error: wrong arguments\n", 0));
		i++;
	}
	return (1);
}

long	time_stop(struct timeval tv1)
{
	struct timeval	tv2;

	gettimeofday(&tv2, 0);
	return ((tv2.tv_sec - tv1.tv_sec) * 1000
		+ (tv2.tv_usec - tv1.tv_usec) / 1000);
}

void	wait_threads(pthread_t *p, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_detach(*(p + i)) != 0)
		{
			printf("Error: 'tread detach' error\n");
			break ;
		}
		i++;
	}
	free(p);
}

pthread_mutex_t	*get_my_left_fork(t_data *data)
{
	if (data->id != 1)
		return (&data->forks[data->id - 2]);
	return (&data->forks[data->n - 1]);
}

void	*return_and_unlock(pthread_mutex_t *first, pthread_mutex_t *second)
{
	if (first)
		pthread_mutex_unlock(first);
	if (second)
		pthread_mutex_unlock(second);
	return (NULL);
}
