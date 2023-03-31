/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:18:47 by thfavre           #+#    #+#             */
/*   Updated: 2023/03/31 17:44:42 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

typedef struct s_init_data
{
	int				i;
	t_philos_stats	stats;
	t_fork			*forks;
	t_stop			*stop;
}				t_init_data;

static void	init_philo(t_philo *philo, int i, t_init_data *init_data)
{
	philo->id = i;
	pthread_mutex_init(&(init_data->forks[i].mutex), NULL);
	init_data->forks[i].is_taken = false;
	philo->forks = init_data->forks;
	philo->stop = init_data->stop;
	philo->time_to_die = init_data->stats.time_to_die;
	philo->time_to_eat = init_data->stats.time_to_eat;
	philo->time_to_sleep = init_data->stats.time_to_sleep;
	philo->philos_numbers = init_data->stats.philos_numbers;
	philo->meal_number = 0;
	philo->meal_goal = init_data->stats.meal_goal;
}

t_philo	*init_philos(t_philos_stats stats)
{
	t_philo			*philos;
	t_fork			*forks;
	t_stop			*stop;
	pthread_mutex_t	*stop_mutex;
	t_init_data		init_data;

	philos = malloc(sizeof(*philos) * stats.philos_numbers);
	forks = malloc(sizeof(*forks) * stats.philos_numbers);
	stop = malloc(sizeof(*stop));
	stop_mutex = malloc(sizeof(*stop_mutex));
	pthread_mutex_init(stop_mutex, NULL);
	stop->mutex = stop_mutex;
	stop->finish_counter = 0;
	stop->status = false;
	init_data = (t_init_data){-1, stats, forks, stop};
	while (++init_data.i < stats.philos_numbers)
		init_philo(&philos[init_data.i], init_data.i, &init_data);
	return (philos);
}

static void	create_threads(t_philos_stats stats, t_philo *philos,
							pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < stats.philos_numbers)
		pthread_create(&(threads[i]), NULL, brain, &(philos[i]));
}

void	start_philos(t_philos_stats stats, t_philo *philos)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(*threads) * stats.philos_numbers);
	create_threads(stats, philos, threads);
	i = 0;
	while (i < stats.philos_numbers)
		pthread_join(threads[i++], NULL);
}

// ps = philos_stats
int	main(int ac, char **av)
{
	t_philos_stats	ps;
	t_philo			*philos;
	unsigned int	nb_philos_must_eat;
	int				i;

	if (ac < 5 || ac > 6)
		return (printf("You should have 4 or 5 arugments!\n"));
	nb_philos_must_eat = 0;
	if (ac == 6)
		nb_philos_must_eat = ft_atoi(av[5]);
	ps = (t_philos_stats){ft_atoi(av[1]), ft_atoi(av[2]),
		ft_atoi(av[3]), ft_atoi(av[4]), nb_philos_must_eat};
	if (ps.philos_numbers < 1 || ps.time_to_die < 1 || ps.time_to_eat < 1
		|| ps.time_to_sleep <= 0 || ps.meal_goal == -1)
		return (printf("I can only accept Integers > 0 !\n"));
	philos = init_philos(ps);
	start_philos(ps, philos);
	i = -1;
	while (++i < ps.philos_numbers)
		pthread_mutex_destroy(&(philos[i].forks[i].mutex));
	free(philos[0].forks);
	pthread_mutex_destroy(philos[0].stop->mutex);
	free(philos[0].stop->mutex);
	free(philos[0].stop);
	free(philos);
}
