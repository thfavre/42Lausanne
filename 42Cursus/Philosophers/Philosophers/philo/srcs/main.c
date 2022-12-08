
#include "../includes/philo.h"



int main(int argc, char **argv)
{
	// this should be parse from the argv
	int number_of_philosophers = 4;
	// in miliseconds
	int time_to_die = 4000;
	int time_to_eat = 1000;
	int time_to_sleep = 10000;
	// number_of_times_each_philosopher_must_eat // optional

	t_philosopher	*philosophers_data = malloc(sizeof(*philosophers_data) * number_of_philosophers);
	pthread_t	*threads = malloc(sizeof(*threads) * number_of_philosophers);
	pthread_mutex_t	*forks_mutexes = malloc(sizeof(*forks_mutexes) * number_of_philosophers);
	int i = 0;
	int res;
	pthread_mutex_t	can_speak_mutex;// = PTHREAD_MUTEX_INITIALIZER;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&(forks_mutexes[i]), NULL);
		pthread_mutex_init(&(can_speak_mutex), NULL);
		philosophers_data[i].id = i;
		philosophers_data[i].state = SLEEPING;
		gettimeofday(&(philosophers_data[i].start_time), NULL); // needed?
		gettimeofday(&(philosophers_data[i].last_eat_time), NULL); // the philosopher come to the table the belly full!
		philosophers_data[i].eat_count = 0;
		philosophers_data[i].activities_times = (t_activities_times){time_to_eat, time_to_sleep, time_to_die};
		philosophers_data[i].can_speak_mutex = &can_speak_mutex;
		gettimeofday(&philosophers_data[i].program_start_time, NULL);
		res = pthread_create(&(threads[i]), NULL, ft_philosopher, &(philosophers_data[i]));
		//printf("i%d\n", i);
		if (res !=0) {//handle error
		}
		i++;
	}
	// wait for the threads to finish
	i = 0;
	while (i < number_of_philosophers)
		pthread_detach(threads[i]);
		//pthread_join(threads[i], NULL);

	printf("end\n");
	return (0);
}
