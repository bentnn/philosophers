#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_data
{
	void			*content;
	struct s_list	*next;
}					t_data;

int	ft_atoi(const char *str);

#endif
