
#include "../includes/philo.h"

bool	should_stop(t_philo *philo)
{
	bool	return_value;
	// if (lock_mutex)
	pthread_mutex_lock(philo->stop->mutex);
	if (philo->stop->status)
	{
		philo->is_dead = true;
		return_value = true;
	}
	else
		return_value = false;
	// if (lock_mutex)
	pthread_mutex_unlock(philo->stop->mutex);
	return (return_value);
}

void	*brain(void *args)
{
	t_philo	*philo = (t_philo*)args;
	philo->is_dead = false;
	// logs(" New philo created ", philo->id);
	if (philo->id % 2)
		usleep(3000);
	philo->last_eat_time = get_time_in_ms();
	// pthread_mutex_lock(philo->stop->mutex);

	while (!philo->is_dead)
	{
			// printf("%d\n", philo->id);
			//logs(" New philo created ", philo);

		die(philo);
		think(philo);
		eat(philo);
		dream(philo);
	}

	return (NULL);
}

void	die(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	if (philo->last_eat_time + philo->time_to_die < get_time_in_ms())
	{

		// should_stop(philo);
		// if (philo->stop->status == false)
		logs("\033[0;31mdied\033[0m", philo, true);

		// pthread_mutex_unlock(philo->stop->mutex);
	}
}

bool	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	if (!fork->is_taken)
	{
		fork->is_taken = true;
		pthread_mutex_unlock(&fork->mutex);
		logs("\033[0;36mhas taken a fork\033[0m", philo, false);
		return (true);
	}
	pthread_mutex_unlock(&fork->mutex);
	return (false);
}

void	release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->is_taken = false;
	pthread_mutex_unlock(&fork->mutex);
}

void	think(t_philo *philo)
{
	bool	is_thinking;

	//die(philo);
	if (philo->is_dead)
		return ;
	is_thinking = false;
	// if (!is_thinking)
	// 		logs("\033[0;35mis thinking\033[0m", philo->id);
	philo->fork_in_hand_numbers = 0;
	while (!philo->is_dead && philo->fork_in_hand_numbers != 2)
	{
		if (take_fork(philo, &philo->forks[philo->id]))
			{
				philo->fork_in_hand_numbers++;
				// logs("\033[0;36mhas taken a fork\033[0m", philo);
			}
		if (take_fork(philo, &philo->forks[(philo->id + 1) % philo->philos_numbers]))
		{
			philo->fork_in_hand_numbers++;
			// logs("\033[0;36mhas taken a fork\033[0m", philo);
		}
		if (philo->fork_in_hand_numbers != 2 && !is_thinking)
		// if (take_fork(&philo->forks[philo->id]))
		// {
		// 	if (take_fork(&philo->forks[(philo->id + 1) % philo->philos_numbers]))
		// 		return ;
			//release_fork(&philo->forks[philo->id]);
		// }
		// if (!is_thinking)
		// 	logs("is thinking", philo->id);
		is_thinking = true;
		die(philo);
	}
}

void	eat(t_philo *philo)
{
	int	start_eat_time;

	if (philo->is_dead)
		return ;
	start_eat_time = get_time_in_ms();
	should_stop(philo);
	logs("\033[0;32mis eating\033[0m", philo, false);
	philo->last_eat_time = get_time_in_ms();
	while (!philo->is_dead && start_eat_time + philo->time_to_eat > get_time_in_ms())
		die(philo);
	if (!philo->is_dead)
	{
		philo->meal_number++;
		if (philo->meal_number == philo->meal_goal)
		{
			pthread_mutex_lock(philo->stop->mutex);
			philo->stop->finish_counter++;
			if (philo->stop->finish_counter == philo->philos_numbers)
				philo->stop->status = true;
			pthread_mutex_unlock(philo->stop->mutex);
		}
	}
	release_fork(&philo->forks[philo->id]);
	release_fork(&philo->forks[(philo->id + 1) % philo->philos_numbers]);
}

void	dream(t_philo *philo)
{
	int	start_sleep_time;

	//die(philo);
	if (philo->is_dead)
		return ;
	start_sleep_time = get_time_in_ms();
	logs("\033[0;30mis sleeping\033[0m", philo, false);
	while (!philo->is_dead && start_sleep_time + philo->time_to_sleep > get_time_in_ms())
		die(philo);
}

