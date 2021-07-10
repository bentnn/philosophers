#include "philo.h"

void	sleep_in_time(t_data *data, int time)
{
	int	need;

	need = (int) time_stop(data->start) + time;
	while ((int)time_stop(data->start) < need)
		usleep(100);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;

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

void	write_message(const char *str, t_data *data)
{
	int	i;

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

void	free_data_if_error(t_data *data)
{
	free(data->stop);
	free(data->forks);
	free(data);
}
