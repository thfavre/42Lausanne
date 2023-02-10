
#include "../includes/philo.h"

typedef struct s_philos_stats
{
	unsigned int	philos_numbers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	meal_goal;

}	t_philos_stats;


void	init_philos(t_philos_stats stats)
{

	t_philo			*philos = malloc(sizeof(*philos) * stats.philos_numbers);
	t_fork			*forks = malloc(sizeof(*forks) * stats.philos_numbers);
	pthread_t		*threads = malloc(sizeof(*threads) * stats.philos_numbers);
	t_stop			stop;
	pthread_mutex_t	stop_mutex;

	pthread_mutex_init(&stop_mutex, NULL);
	stop = (t_stop){stop_mutex, 0, false};
	int	i;
	i = 0;
	while (i < stats.philos_numbers)
	{
		philos[i].id = i;
		pthread_mutex_init(&(forks[i].mutex), NULL);
		forks[i].is_taken = false;
		philos[i].forks = forks;
		philos[i].stop = &stop;
		philos[i].time_to_die = stats.time_to_die;
		philos[i].time_to_eat = stats.time_to_eat;
		philos[i].time_to_sleep = stats.time_to_sleep;
		philos[i].philos_numbers = stats.philos_numbers;
		philos[i].meal_number = 0;
		philos[i].meal_goal = stats.meal_goal;
		pthread_create(&(threads[i]), NULL, brain, &(philos[i]));
		i++;
	}
	i = 0;
	while (i < stats.philos_numbers)
		pthread_join(threads[i++], NULL);
	// Free
}

int main(int argc, char **argv)
{
	int philos_numbers = 1;
	int time_to_die = 300;
	int time_to_eat = 200;
	int time_to_sleep = 200;
	t_philos_stats philos_stats;
	unsigned int number_of_times_each_philosopher_must_eat = 40;

	philos_stats = (t_philos_stats){6, 300, 200, 200, 40};
	init_philos(philos_stats);



		//pthread_detach(threads[i]);
	// USEFUL ?int pthread_mutex_destroy(pthread_mutex_t *mutex);
	// TODO free malocs
}
