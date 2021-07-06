#include "philo.h"

void *routine_right(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	gettimeofday(&data->last_eating, 0);
	while (*data->stop != 1)
	{
		pthread_mutex_lock(&data->forks[data->id - 1]);
		pthread_mutex_lock(&data->outp);
		if (*data->stop == 1)
			return (return_and_unlock(&data->outp, &data->forks[data->id - 1]));
		printf("%ldms %d has taken a fork\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
		pthread_mutex_lock(get_my_left_fork(data));
		pthread_mutex_lock(&data->outp);
		if (*data->stop == 1)
		{
			pthread_mutex_unlock(get_my_left_fork(data));
			return ((return_and_unlock(&data->outp, &data->forks[data->id - 1])));
		}
		printf("%ldms %d has taken a fork\n", time_stop(data->start), data->id);
		data->is_eating = 1;
		printf("%ldms %d is eating\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
		usleep(data->tte * 1000);
		pthread_mutex_unlock(&data->forks[data->id - 1]);
		pthread_mutex_unlock(get_my_left_fork(data));
		gettimeofday(&data->last_eating, 0);
		data->is_eating = 0;
		data->ntme -= (data->ntme > 0);
		if (data->ntme == 0)
			return (0);
		pthread_mutex_lock(&data->outp);
		if (*data->stop == 1)
			return  (return_and_unlock(&data->outp, 0));
		printf("%ldms %d is sleeping\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
		usleep(data->tts * 1000);
		pthread_mutex_lock(&data->outp);
		if (*data->stop == 1)
			return (return_and_unlock(&data->outp, 0));
		printf("%ldms %d is thinking\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
	}
	return (0);
}

void *routine_left(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	gettimeofday(&data->last_eating, 0);
	while (*data->stop != 1)
	{
		pthread_mutex_lock(get_my_left_fork(data));
		pthread_mutex_lock(&data->outp);
		if (*data->stop == 1)
			return (return_and_unlock(&data->outp, &data->forks[data->id - 1]));
		printf("%ldms %d has taken a fork\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
		pthread_mutex_lock(&data->forks[data->id - 1]);
		pthread_mutex_lock(&data->outp);
		if (*data->stop == 1)
		{
			pthread_mutex_unlock(get_my_left_fork(data));
			return ((return_and_unlock(&data->outp, &data->forks[data->id - 1])));
		}
		printf("%ldms %d has taken a fork\n", time_stop(data->start), data->id);
		data->is_eating = 1;
		printf("%ldms %d is eating\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
		usleep(data->tte * 1000);
		pthread_mutex_unlock(&data->forks[data->id - 1]);
		pthread_mutex_unlock(get_my_left_fork(data));
		gettimeofday(&data->last_eating, 0);
		data->is_eating = 0;
		data->ntme -= (data->ntme > 0);
		if (data->ntme == 0)
			return (0);
		pthread_mutex_lock(&data->outp);

		if (*data->stop == 1)
			return  (return_and_unlock(&data->outp, 0));
		printf("%ldms %d is sleeping\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
		usleep(data->tts * 1000);
		pthread_mutex_lock(&data->outp);
		if (*data->stop == 1)
			return (return_and_unlock(&data->outp, 0));
		printf("%ldms %d is thinking\n", time_stop(data->start), data->id);
		pthread_mutex_unlock(&data->outp);
	}
	return (0);
}

void check_a_death(t_data **array)
{
	int i;
	int ate;

	i = 0;
	ate = 0;
	while (i < array[0]->n)
	{
		if (array[i]->is_eating == 0 && time_stop(array[i]->last_eating) >= array[i]->ttd)
		{
			*array[i]->stop = 1;
			pthread_mutex_lock(&array[i]->outp);
			printf("%ldms %d died\n", time_stop(array[i]->start), array[i]->id);
			pthread_mutex_unlock(&array[i]->outp);
			return;
		}
		ate += (array[i]->ntme == 0);
		i++;
	}
	if (ate == array[0]->n)
		*array[0]->stop = 1;
}

void	end_of_main(pthread_t *p, t_data *data, t_data **temp)
{
	int	i;


	wait_threads(p, data->n);
	i = 0;
	while (i < data->n)
	{
		free(temp[i]);
		i++;
	}
	delete_data(data);
	free(temp);
}

int main(int argc, char **argv)
{
	int i;
	void *func;
	t_data *data;
	t_data **temp;
	pthread_t *p;

	if (!check_args(argc, argv))
		return (1);
	data = create_simple_data(argc, argv, ft_atoi(argv[1]));
	if (data == NULL)
		return (error_with_message("Error: malloc error\n", 1));
	p = malloc(sizeof(pthread_t) * data->n);
	if (!p)
	{
		free(data);
		return (error_with_message("Error: malloc error\n", 1));
	}
	temp = creeate_array_of_data(data);
	if (!temp)
	{
		free(data);
		free(p);
		return (error_with_message("Error: malloc error\n", 1));
	}
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
				end_of_main(p, data, temp);
				return (error_with_message("Error: 'tread create' error\n", 1));
			}
		i++;
		usleep(50);
	}
	while (*data->stop == 0)
	{
		check_a_death(temp);
		usleep(100);
	}
	end_of_main(p, data, temp);
	return (0);
}
