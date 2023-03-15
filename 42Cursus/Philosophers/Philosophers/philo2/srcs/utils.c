
#include "../includes/philo.h"

void	logs(char *msg, t_philo *philo)
{
	// pthread_mutex_lock(&philo->stop->mutex);
	if (!should_stop(philo))
	// if (!philo->is_dead)
		printf("%i\t %d\t %s, %d\n", get_time_in_ms(), philo->id + 1, msg, philo->meal_number);
	// pthread_mutex_unlock(&philo->stop->mutex);
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
