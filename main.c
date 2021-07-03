#include "philo.h"

int error_with_message(const char *str)
{
	printf("%s", str);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc < 5)
		return (error_with_message("Error: wrong number of arguments\n"));
	return 0;
}
