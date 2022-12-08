
#include "../includes/philo.h"

double	get_time_in_ms(struct timeval time)
{

	double time_in_ms;

	time_in_ms = time.tv_sec * 1000.0 + time.tv_usec / 1000.0;
	return (time_in_ms); // remove the variable
}
