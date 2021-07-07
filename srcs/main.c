#include "philo.h"

void	check_a_death(t_data **array)
{
	int	i;
	int	ate;

	i = 0;
	ate = 0;
	while (i < array[0]->n)
	{
		if (array[i]->is_eating == 0
			&& time_stop(array[i]->last_eating) >= array[i]->ttd)
		{
			*array[i]->stop = 1;
			pthread_mutex_lock(&array[i]->outp);
			printf("%ldms %d died\n", time_stop(array[i]->start), array[i]->id);
			pthread_mutex_unlock(&array[i]->outp);
			return ;
		}
		ate += (array[i]->ntme == 0);
		i++;
	}
	if (ate == array[0]->n)
		*array[0]->stop = 1;
}

void	end_of_main(pthread_t *p, t_data *data, t_data **temp, int n)
{
	int	i;

	wait_threads(p, n);
	i = 0;
	while (i < data->n)
	{
		free(temp[i]);
		i++;
	}
	delete_data(data);
	free(temp);
}

int	start_sim(t_data *data, t_data **temp, pthread_t *p)
{
	int		i;
	void	*func;

	i = 0;
	while (i < data->n)
	{
		gettimeofday(&temp[i]->start, 0);
		if (i % 2 == 0)
			func = routine_right;
		else
			func = routine_left;
		if (pthread_create(&p[i], NULL, func, temp[i]) != 0)
		{
			*data->stop = 1;
			end_of_main(p, data, temp, i);
			return (error_with_message("Error: 'tread create' error\n", 1));
		}
		i++;
		usleep(50);
	}
	return (0);
}

int	malloc_p_and_temp(pthread_t **p, t_data ***temp, t_data *data)
{
	*p = malloc(sizeof(pthread_t) * data->n);
	if (!*p)
	{
		free(data);
		return (error_with_message("Error: malloc error\n", 1));
	}
	*temp = creeate_array_of_data(data);
	if (!*temp)
	{
		free(data);
		free(*p);
		return (error_with_message("Error: malloc error\n", 1));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_data		**temp;
	pthread_t	*p;

	if (!check_args(argc, argv))
		return (1);
	data = create_simple_data(argc, argv, ft_atoi(argv[1]));
	if (data == NULL)
		return (error_with_message("Error: malloc error\n", 1));
	if (malloc_p_and_temp(&p, &temp, data) == 1)
		return (1);
	if (start_sim(data, temp, p) == 1)
		return (1);
	while (*data->stop == 0)
	{
		check_a_death(temp);
		usleep(100);
	}
	end_of_main(p, data, temp, data->n);
	return (0);
}
