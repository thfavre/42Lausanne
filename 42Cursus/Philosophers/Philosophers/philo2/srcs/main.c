
#include "../includes/philo.h"


int main(int argc, char **argv)
{
	int philos_numbers = 2;
	int time_to_die = 310;
	int time_to_eat = 200;
	int time_to_sleep = 200;
	unsigned int number_of_times_each_philosopher_must_eat = 0;

	t_philo			*philos = malloc(sizeof(*philos) * philos_numbers);
	t_fork			*forks = malloc(sizeof(*forks) * philos_numbers);
	pthread_t		*threads = malloc(sizeof(*threads) * philos_numbers);
	t_stop	stop;
	pthread_mutex_t	stop_mutex;

	pthread_mutex_init(&stop_mutex, NULL);
	stop = (t_stop){stop_mutex, false};
	int	i;
	i = 0;
	while (i < philos_numbers)
	{
		philos[i].id = i;
		pthread_mutex_init(&(forks[i].mutex), NULL);
		forks[i].is_taken = false;
		philos[i].forks = forks;
		// philos[i].stop.mutex = &stop_mutex; //same address
		// philos[i].stop.should_stop = false;
		// philos[i].stop.counter = false;
		philos[i].stop = &stop;
		philos[i].time_to_die = time_to_die;
		philos[i].time_to_eat = time_to_eat;
		philos[i].time_to_sleep = time_to_sleep;
		philos[i].philos_numbers = philos_numbers;
		philos[i].meal_number = 0;
		//philos[i].meal_number = philos_numbers;
		pthread_create(&(threads[i]), NULL, brain, &(philos[i]));
		i++;
	}

	i = 0;
	while (i < philos_numbers)
		pthread_join(threads[i++], NULL);
		//pthread_detach(threads[i]);
	// USEFUL ?int pthread_mutex_destroy(pthread_mutex_t *mutex);
	// TODO free malocs
}
