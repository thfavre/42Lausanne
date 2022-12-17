
#include "../includes/philo.h"

void	*ft_philosopher(void *arg)
{
	t_philosopher	*philosopher = (t_philosopher*)arg;
	printf("A new philosopher thread has been created! (id = %d)\n", philosopher->id);
	while (1)
	{
		think(philosopher);
		if (isDead(philosopher))
			break;

		eat(philosopher);

		if (isDead(philosopher))
		{
			break;
		}

		sleep_(philosopher);
		if (isDead(philosopher))
		{
			break;
		}
	}

	pthread_mutex_lock(philosopher->can_speak_mutex);
	printf("Amen (id=%d)\n", philosopher->id);
	pthread_mutex_unlock(philosopher->can_speak_mutex);
	return (NULL);
}

void	eat(t_philosopher *philosopher)
{

	struct timeval	current_time;

	philosopher->state = EATING;

	pthread_mutex_lock(philosopher->can_speak_mutex);
	gettimeofday(&current_time, NULL);
	printf("%f %d is eating\n", get_time_in_ms(current_time) - get_time_in_ms(philosopher->program_start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->can_speak_mutex);

	usleep(philosopher->activities_times.eat * 1000);

	philosopher->eat_count++;
	gettimeofday(&(philosopher->last_eat_time), NULL);
}

void	sleep_(t_philosopher *philosopher)
{
	struct timeval	current_time;

	philosopher->state = SLEEPING;

	pthread_mutex_lock(philosopher->can_speak_mutex);
	gettimeofday(&current_time, NULL);
	printf("%f %d is sleeping\n", get_time_in_ms(current_time) - get_time_in_ms(philosopher->program_start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->can_speak_mutex);

	gettimeofday(&philosopher->start_time, NULL);
	while (!isDead(philosopher))
	{
		// checks if his task is finished
		gettimeofday(&current_time, NULL);
		if (get_time_in_ms(philosopher->start_time) + philosopher->activities_times.sleep < get_time_in_ms(current_time)) // the task is finished
		{
			break ;
		}

		// should I sleep 5 ms?

	}
}

void	think(t_philosopher *philosopher)
{
	struct timeval	current_time;

	pthread_mutex_lock(philosopher->can_speak_mutex);
	gettimeofday(&current_time, NULL);
	printf("%f %d is thinking\n", get_time_in_ms(current_time) - get_time_in_ms(philosopher->program_start_time), philosopher->id);
	pthread_mutex_unlock(philosopher->can_speak_mutex);

	// while 2 forks are not available, sleep


}

bool isDead(t_philosopher *philosopher)
{
	struct timeval	current_time;
	double elapsed_time_in_ms;
	struct timeval start;
	struct timeval now;

	if (philosopher->state == DEAD)
		return (true);
	start = philosopher->last_eat_time;
	gettimeofday(&now, NULL);

	if (get_time_in_ms(philosopher->last_eat_time) + philosopher->activities_times.die < get_time_in_ms(now))
	{
		philosopher->state = DEAD;
		pthread_mutex_lock(philosopher->can_speak_mutex);
		gettimeofday(&current_time, NULL);
		printf("%f %d died\n", get_time_in_ms(current_time) - get_time_in_ms(philosopher->program_start_time), philosopher->id);
		pthread_mutex_unlock(philosopher->can_speak_mutex);
		return (true);
	}
	return (false);
}
