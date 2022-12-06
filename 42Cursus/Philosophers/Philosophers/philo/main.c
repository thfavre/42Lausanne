#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

enum e_state
{
	EATING,
	THINKING,
	SLEEPING,
	DEAD
}	;

typedef struct s_activity_times
{
	int	eat;
	int	sleep;
	int	die;

}	t_activities_times;

typedef struct s_philosopher
{
	int					id;
	enum e_state		state;
	struct timeval		start_time;
	struct timeval		last_eat_time;
	int					eat_count;
	t_activities_times	activities_times;
	pthread_mutex_t		*can_speak_mutex;
}						t_philosopher;

void	eat(t_philosopher *philosopher)
{
	philosopher->state = EATING;
	
	pthread_mutex_lock(philosopher->can_speak_mutex);
	printf("miam miam, I am eating (id=%d)\n", philosopher->id);
	pthread_mutex_unlock(philosopher->can_speak_mutex);
	
	usleep(philosopher->activities_times.eat);
	philosopher->eat_count++;
	gettimeofday(&(philosopher->last_eat_time), NULL);
}

double	get_time_in_ms(struct timeval time)
{

	double time_in_ms;

	time_in_ms = time.tv_sec * 1000.0 + time.tv_usec / 1000.0;
	return (time_in_ms); // remove the variable
}

double	get_elapsed_time_in_ms_between_two_times(struct timeval time1, struct timeval time2)
{

	double elapsed_time_in_ms;
	//elapsed_time_in_ms = (time2.tv_sec - time1.tv_sec) * 1000.0
	//	               + (time2.tv_usec - time1.tv_usec) / 1000.0;
	//elapsed_time_in_ms = get_time_in_ms(time)
	return (elapsed_time_in_ms);
}

bool isDead(t_philosopher *philosopher)
{
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
		return (true);
	}
	return (false);
}

void	sleep_(t_philosopher *philosopher)
{
	struct timeval	current_time;

	philosopher->state = SLEEPING;
	pthread_mutex_lock(philosopher->can_speak_mutex);
	printf("Zzz.. I am sleeping (id=%d)\n", philosopher->id);
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
	
	pthread_mutex_lock(philosopher->can_speak_mutex);
	printf("I am genuis and thinking... (id=%d)\n", philosopher->id);
	pthread_mutex_unlock(philosopher->can_speak_mutex);
	// while 2 forks are not available, sleep 
	
}


void	*ft_philosopher(void *arg)
{
	t_philosopher	*philosopher = (t_philosopher*)arg;
	printf("A new philosopher thread has been created! (id = %d)\n", philosopher->id);
	while (1)
	{
		think(philosopher);
		if (isDead(philosopher))
		{
			pthread_mutex_lock(philosopher->can_speak_mutex);
			printf("Philo (id = %d) just die...\n", philosopher->id);
			pthread_mutex_unlock(philosopher->can_speak_mutex);
	//		break;
		}
		eat(philosopher);
		if (isDead(philosopher))
		{
			pthread_mutex_lock(philosopher->can_speak_mutex);
			printf("Philo (id = %d) just die...\n", philosopher->id);
			pthread_mutex_unlock(philosopher->can_speak_mutex);
	//		break;
		}
		sleep_(philosopher);
		if (isDead(philosopher))
		{
			pthread_mutex_lock(philosopher->can_speak_mutex);
			printf("Philo (id = %d) just die...\n", philosopher->id);
			pthread_mutex_unlock(philosopher->can_speak_mutex);
	//		break;
		}
	}
}


int main(int argc, char **argv)
{
	// this should be parse from the argv
	int number_of_philosophers = 4;
	// in miliseconds
	int time_to_die = 4000; 
	int time_to_eat = 1000;
	int time_to_sleep = 1000;
	// number_of_times_each_philosopher_must_eat // optional
	
	t_philosopher	*philosophers_data = malloc(sizeof(*philosophers_data) * number_of_philosophers);
	pthread_t	*threads = malloc(sizeof(*threads) * number_of_philosophers);
	pthread_mutex_t	*forks_mutexes = malloc(sizeof(*forks_mutexes) * number_of_philosophers);
	int i = 0;
	int res;
	pthread_mutex_t	can_speak_mutex = PTHREAD_MUTEX_INITIALIZER;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&(forks_mutexes[i]), NULL);
		philosophers_data[i].id = i;
		philosophers_data[i].state = SLEEPING;
		gettimeofday(&(philosophers_data[i].start_time), NULL); // needed?
		gettimeofday(&(philosophers_data[i].last_eat_time), NULL); // the philosopher come to the table the belly full! 
		philosophers_data[i].eat_count = 0;
		philosophers_data[i].activities_times = (t_activities_times){time_to_eat, time_to_sleep, time_to_die};
		philosophers_data[i].can_speak_mutex = &can_speak_mutex;
		res = pthread_create(&(threads[i]), NULL, ft_philosopher, &(philosophers_data[i]));
		printf("i%d\n", i);
		if (res !=0) {//handle error
		}
		i++;
	}
	// wait for the threads to finish
	while (i < number_of_philosophers)
		pthread_join(threads[i], NULL);

	printf("end\n");
	return (0);
}
