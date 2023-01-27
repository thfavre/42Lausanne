
#include "../includes/philo.h"

void	logs(char *msg, int id)
{
	printf("%i %d %s\n", get_time_in_ms(), ++id, msg);
}

int	get_time_in_ms(void)
{
	static struct timeval	start_time = {0};
	struct timeval			time;

	gettimeofday(&time, NULL);
	if (start_time.tv_sec == 0)
		{start_time = time;}
	return ((time.tv_sec - start_time.tv_sec) * 1000 + (time.tv_usec -start_time.tv_usec )/ 1000);
}
