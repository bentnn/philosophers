#include "philo.h"

int	ft_atoi(const char *str)
{
	int				minus;
	unsigned long	result;

	minus = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n'
					|| *str == '\v' || *str == '\f'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		if (result > LONG_MAX && minus == 1)
			return (-1);
		if (result > LONG_MAX && minus == -1)
			return (0);
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((int)result * minus);
}

int ft_isdigit(int ch)
{
	return (ch > 47 && ch < 58);
}