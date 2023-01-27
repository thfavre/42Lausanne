
#include "../includes/philo.h"


int main(int argc, char **argv)
{
	int philos_numbers = 4;
	int time_to_die = 310;
	int time_to_eat = 200;
	int time_to_sleep = 100;


	t_philo			*philos = malloc(sizeof(*philos) * philos_numbers);
	t_fork			*forks = malloc(sizeof(*forks) * philos_numbers);
	pthread_t		*threads = malloc(sizeof(*threads) * philos_numbers);
	int	i;

	i = 0;
	while (i < philos_numbers)
	{
		philos[i].id = i;
		pthread_mutex_init(&(forks[i].mutex), NULL);
		forks[i].is_taken = false;
		philos[i].forks = forks;
		philos[i].time_to_die = time_to_die;
		philos[i].time_to_eat = time_to_eat;
		philos[i].time_to_sleep = time_to_sleep;
		philos[i].philos_numbers = philos_numbers;
		pthread_create(&(threads[i]), NULL, brain, &(philos[i]));
		i++;
	}

	i = 0;
	while (i < philos_numbers)
		pthread_join(threads[i++], NULL);
		//pthread_detach(threads[i]);
	// USEFUL ?int pthread_mutex_destroy(pthread_mutex_t *mutex);
}
