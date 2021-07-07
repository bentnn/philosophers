#include "philo.h"

static t_data	*make_malloc(int n)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->stop = malloc(sizeof(int));
	if (!data->stop)
	{
		free(data);
		return (NULL);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!data->forks)
	{
		free(data->stop);
		free(data);
		return (NULL);
	}
	return (data);
}

t_data	*create_simple_data(int argc, char **argv, int n)
{
	t_data	*data;

	data = make_malloc(n);
	if (!data)
		return (NULL);
	*data->stop = 0;
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	data->n = n;
	data->ntme = -1;
	if (argc == 6)
		data->ntme = ft_atoi(argv[5]);
	pthread_mutex_init(&data->outp, NULL);
	n = 0;
	while (n < data->n)
	{
		pthread_mutex_init(&data->forks[n], NULL);
		n++;
	}
	return (data);
}

void	delete_data(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->outp);
	i = 0;
	while (i < data->n)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->stop);
	free(data->forks);
	free(data);
}

t_data	*copy_data(t_data *data)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->start = data->start;
	new->forks = data->forks;
	new->stop = data->stop;
	new->outp = data->outp;
	new->tts = data->tts;
	new->tte = data->tte;
	new->ttd = data->ttd;
	new->ntme = data->ntme;
	new->n = data->n;
	new->is_eating = 0;
	return (new);
}

t_data	**creeate_array_of_data(t_data *data)
{
	t_data	**res;
	int		i;

	res = malloc(sizeof(t_data *) * data->n);
	if (!res)
		return (0);
	i = 0;
	while (i < data->n)
	{
		res[i] = copy_data(data);
		if (!res[i])
		{
			i--;
			while (i >= 0)
			{
				free(res[i]);
				i--;
			}
			free(res);
			return (0);
		}
		res[i]->id = i + 1;
		i++;
	}
	return (res);
}
