
#include "../includes/philo.h"

void	*brain(void *args)
{
	t_philo	*philo = (t_philo*)args;
	//philo->last_eat_time = get_time_in_ms();
	philo->is_dead = false;
	logs(" New philo created ", philo->id);

	while (!philo->is_dead)
	{
		die(philo);
		think(philo);
		eat(philo);
		dream(philo);

	}

	return (NULL);
}

void	die(t_philo *philo)
{
	if (philo->last_eat_time + philo->time_to_eat < get_time_in_ms())
	{
		philo->is_dead = true;
		logs("died", philo->id);
	}
}

void	think(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	logs("is thinking", philo->id);

}


void	eat(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	logs("is eating", philo->id);
	usleep(philo->time_to_eat * 1000);
	philo->last_eat_time = get_time_in_ms();
}

void	dream(t_philo *philo)
{
	int	start_sleep_time;

	if (philo->is_dead)
		return ;
	start_sleep_time = get_time_in_ms();
	logs("is sleeping", philo->id);
	while (!philo->is_dead && start_sleep_time + philo->time_to_sleep > get_time_in_ms())
		die(philo);
}

