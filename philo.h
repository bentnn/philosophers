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
	int is_eating;
	int *stop;
	pthread_mutex_t outp;
	pthread_mutex_t *forks;
	struct timeval start;
	struct timeval last_eating;
}					t_data;

int	ft_atoi(const char *str);
int ft_isdigit(int ch);
t_data *create_simple_data(int argc, char **argv, int n);
void delete_data(t_data *data);
t_data *copy_data(t_data *data);
t_data **creeate_array_of_data(t_data *data);
int error_with_message(const char *str, int res);
int is_pos_int(char *str);
int ft_strlen(const char *str);
int check_args(int argc, char **argv);
long time_stop(struct timeval tv1);
void wait_threads(pthread_t *p, int n);
pthread_mutex_t *get_my_left_fork(t_data *data);
void *return_and_unlock(pthread_mutex_t *first, pthread_mutex_t *second);


#endif
