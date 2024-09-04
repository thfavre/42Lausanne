/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:31:31 by thfavre           #+#    #+#             */
/*   Updated: 2023/05/22 14:14:05 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*brain(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->is_dead = false;
	if (philo->id % 2 == 0)
		usleep(3000);
	philo->last_eat_time = get_time_ms();
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
	if (philo->is_dead)
		return ;
	if (philo->last_eat_time + philo->time_to_die < get_time_ms())
		logs("\033[1;31mdied\033[0m", philo, true);
}

void	think(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	logs("\033[1;30mis thinking\033[0m", philo, false);
	philo->fork_in_hand_numbers = 0;
	while (!philo->is_dead && philo->fork_in_hand_numbers != 2)
	{
		if (take_fork(philo, &philo->forks[philo->id]))
				philo->fork_in_hand_numbers++;
		if (take_fork(philo, &philo->forks[(philo->id + 1) % \
				philo->philos_numbers]))
			philo->fork_in_hand_numbers++;
		die(philo);
	}
}

void	eat(t_philo *philo)
{
	int	eat_time;

	if (philo->is_dead)
		return ;
	eat_time = get_time_ms();
	logs("\033[1;32mis eating\033[0m", philo, false);
	philo->last_eat_time = get_time_ms();
	while (!philo->is_dead && eat_time + philo->time_to_eat > get_time_ms())
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

	if (philo->is_dead)
		return ;
	start_sleep_time = get_time_ms();
	logs("\033[1;35mis sleeping\033[0m", philo, false);
	while (!philo->is_dead && \
		start_sleep_time + philo->time_to_sleep > get_time_ms())
		die(philo);
}
