#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data
{
	int id;
	int ttd;
	int tte;
	int tts;
	int ntme;
	int n;
	int *stop;
	pthread_mutex_t outp;
	pthread_mutex_t *forks;
	struct timeval start;
}					t_data;

int	ft_atoi(const char *str);
int ft_isdigit(int ch);

#endif
