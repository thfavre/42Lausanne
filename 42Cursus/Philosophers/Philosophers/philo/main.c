#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

enum e_state
{
	EATING,
	THINKING,
	SLEEPING,
}	;

typedef struct s_philosopher
{
	int				id;
	enum e_state	state;a
	struct timeval	start_time;
	int				eat_count;

}					t_philosopher;


void	*ft_philosopher(void *arg)
{
	printf("A new philosopher thread has been created!\n");
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
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&(forks_mutexes[i]), NULL);
		philosophers_data[i].id = i;
		philosophers_data[i].state = SLEEPING;
		gettimeofday(&(philosophers_data[i].start_time), NULL);
		philosophers_data[i].eat_count = 0;
		res = pthread_create(&(threads[i]), NULL, ft_philosopher, &(philosophers_data[i]));
		printf("i%d\n", i);
		if (res !=0) {//handle error
		}
		i++;

	}

	return (0);
}
