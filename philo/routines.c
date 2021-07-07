#include "philo.h"

void	*after_taking_a_forks(t_data *data)
{
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
		return (return_and_unlock(&data->outp, 0));
	printf("%ldms %d is sleeping\n", time_stop(data->start), data->id);
	pthread_mutex_unlock(&data->outp);
	usleep(data->tts * 1000);
	pthread_mutex_lock(&data->outp);
	if (*data->stop == 1)
		return (return_and_unlock(&data->outp, 0));
	printf("%ldms %d is thinking\n", time_stop(data->start), data->id);
	pthread_mutex_unlock(&data->outp);
	return (data);
}

void	*routine_right(void *arg)
{
	t_data	*data;

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
			return ((return_and_unlock(&data->outp,
						&data->forks[data->id - 1])));
		}
		data = (t_data *)after_taking_a_forks(data);
		if (data == NULL)
			return (0);
	}
	return (0);
}

void	*routine_left(void *arg)
{
	t_data	*data;

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
			return ((return_and_unlock(&data->outp,
						&data->forks[data->id - 1])));
		}
		data = (t_data *)after_taking_a_forks(data);
		if (data == NULL)
			return (0);
	}
	return (0);
}
