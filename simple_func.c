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

int	ft_isdigit(int ch)
{
	return (ch > 47 && ch < 58);
}

int	error_with_message(const char *str, int res)
{
	printf("%s", str);
	return (res);
}

int	is_pos_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
