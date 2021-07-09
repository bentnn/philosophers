#include "philo.h"

//int	get_time(t_data *data, int time)
//{
//	int	c;
//
//	c = data->ttd - (int)time_stop(data->last_eating);
//	if (c < time)
//		return (c);
//	return (time);
//}

void sleep_in_time(t_data *data, int time)
{
	int need;

	need = (int) time_stop(data->start) + time;
	while ((int)time_stop(data->start) < need)
		usleep(100);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int temp;
	char c;

	temp = n;
	if (n < 0)
	{
		temp *= -1;
		ft_putchar_fd('-', fd);
	}
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((char)(temp % 10 + 48), fd);
}

void write_message(const char *str, t_data *data)
{
	int i;

	ft_putnbr_fd((int)time_stop(data->start), 1);
	write(1, "ms ", 3);
	ft_putnbr_fd(data->id, 1);
	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	*after_taking_a_forks(t_data *data)
{
	pthread_mutex_lock(&data->deathlock);
	write_message(" has taken a fork\n", data);
	data->is_eating = 1;
	write_message(" is eating\n", data);
	pthread_mutex_unlock(data->outp);
	gettimeofday(&data->last_eating, 0);
	pthread_mutex_unlock(&data->deathlock);
	sleep_in_time(data, data->tte);
	pthread_mutex_unlock(&data->forks[data->id - 1]);
	pthread_mutex_unlock(get_my_left_fork(data));
	data->is_eating = 0;
	data->ntme -= (data->ntme > 0);
	if (data->ntme == 0)
		return (0);
	pthread_mutex_lock(data->outp);
	write_message(" is sleeping\n", data);
	pthread_mutex_unlock(data->outp);
	sleep_in_time(data, data->tts);
	pthread_mutex_lock(data->outp);
	write_message(" is thinking\n", data);
	pthread_mutex_unlock(data->outp);
	return (data);
}

t_data *get_data_from_arg(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	gettimeofday(&data->last_eating, 0);
	if (data->n == 1)
	{
		pthread_mutex_lock(&data->forks[0]);
		pthread_mutex_lock(data->outp);
		write_message(" has taken a fork\n", data);
		write_message(" is thinking\n", data);
		pthread_mutex_unlock(data->outp);
		return (NULL);
	}
	return (data);
}

void	*routine_right(void *arg)
{
	t_data	*data;

	data = get_data_from_arg(arg);
	if (!data)
		return (NULL);
	while (data && arg && *data->stop != 1)
	{
		pthread_mutex_lock(&data->forks[data->id - 1]);
		pthread_mutex_lock(data->outp);
		write_message(" has taken a fork\n", data);
		pthread_mutex_unlock(data->outp);
		pthread_mutex_lock(get_my_left_fork(data));
		pthread_mutex_lock(data->outp);
		data = (t_data *)after_taking_a_forks(data);
	}
	return (0);
}

void	*routine_left(void *arg)
{
	t_data	*data;

	data = get_data_from_arg(arg);
	if (!data)
		return (NULL);
	while (data && arg && *data->stop != 1)
	{
		pthread_mutex_lock(get_my_left_fork(data));
		pthread_mutex_lock(data->outp);
		write_message(" has taken a fork\n", data);
		pthread_mutex_unlock(data->outp);
		pthread_mutex_lock(&data->forks[data->id - 1]);
		pthread_mutex_lock(data->outp);
		data = (t_data *)after_taking_a_forks(data);
	}
	return (0);
}
