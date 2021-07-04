#include "philo.h"

int error_with_message(const char *str, int res)
{
	printf("%s", str);
	return (res);
}

int is_pos_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int check_args(int argc, char **argv)
{
	int i;

	if (argc < 5)
		return (error_with_message("Error: wrong number of arguments\n", 0));
	if (!is_pos_int(argv[1]))
		return (error_with_message("Error: wrong arguments\n", 0));
	i = ft_atoi(argv[1]);
	if (i < 2)
		return (error_with_message("Error: wrong arguments\n", 0));
	if (argc > 5 && argc != 5 + i)
		return (error_with_message("Error: wrong number of arguments\n", 0));
	i = 2;
	while (i < argc)
	{
		if (!is_pos_int(argv[i]))
			return (error_with_message("Error: wrong arguments\n", 0));
		i++;
	}
	return (1);
}

t_data *create_simple_data(char **argv, int n)
{
	t_data *data;
	int i;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->stop = malloc(sizeof(int));
	if (!data->stop)
	{
		free(data);
		return (NULL);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * (n));
	if (!data->forks)
	{
		free(data->stop);
		free(data);
		return (NULL);
	}
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	data->n = n;
	pthread_mutex_init(&data->outp, NULL);
	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (data);
}

void delete_data(t_data *data)
{
	int i;

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

t_data *copy_data(t_data *data)
{
	t_data *new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->forks = data->forks;
	new->stop = data->stop;
	new->outp = data->outp;
	new->tts = data->tts;
	new->tte = data->tte;
	new->ttd = data->ttd;
	new->ntme = -1;
	return (new);
}

long time_stop(struct timeval tv1)
{
	struct timeval tv2;

	gettimeofday(&tv2, 0);
	return ((tv2.tv_sec - tv1.tv_sec) * 1000 + (tv2.tv_usec - tv1.tv_usec) / 1000);
}

void wait_threads(pthread_t *p, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (pthread_join(*(p + i), NULL) != 0)
		{
			printf("Error: tread join error\n");
			break;
		}
		i++;
	}
	free(p);
}

void *routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	printf("Hello from id = %d\n", data->id);
	free(data);
	return (0);
}

int main(int argc, char **argv)
{
	int n;
	int i;
	t_data *data;
	t_data *temp;
	pthread_t *p;
//	gettimeofday(&tv1, 0);
//	usleep(8000);
//	printf("%ld\n", time_stop(tv1));
	if (!check_args(argc, argv))
		return (1);
	n = ft_atoi(argv[1]);
	data = create_simple_data(argv, n);
	if (data == NULL)
		return (error_with_message("Error: malloc error\n", 1));
	p = malloc(sizeof(pthread_t) * n);
	if (!p)
	{
		free(data);
		return (error_with_message("Error: malloc error\n", 1));
	}
	i = 0;
	while (i < data->n)
	{
		temp = copy_data(data);
		temp->id = i + 1;
		if (argc > 5)
			temp->ntme = ft_atoi(argv[5 + i]);
		if (pthread_create(&p[i], NULL, &routine, temp) != 0)
		{
			*data->stop = 1;
			wait_threads(p, i);
			exit(error_with_message("Error: tread create error\n", 1));
		}
		i++;
	}
	wait_threads(p, data->n);
	delete_data(data);
	return (0);
}
