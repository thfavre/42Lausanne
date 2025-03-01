/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:49:05 by thfavre           #+#    #+#             */
/*   Updated: 2023/05/22 14:13:48 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	logs(char *msg, t_philo *philo, bool kill)
{
	pthread_mutex_lock(philo->stop->mutex);
	if (philo->stop->status)
	{
		philo->is_dead = true;
		pthread_mutex_unlock(philo->stop->mutex);
		return ;
	}
	if (philo->stop->status == false)
		printf("%i\t %d\t %s\n", get_time_ms(), philo->id + 1, msg);
	if (kill)
	{
		philo->is_dead = true;
		philo->stop->status = true;
	}
	pthread_mutex_unlock(philo->stop->mutex);
}

int	get_time_ms(void)
{
	static struct timeval	start_time = {0};
	static pthread_mutex_t	start_time_mutex = PTHREAD_MUTEX_INITIALIZER;
	struct timeval			current_time;
	int						time;

	pthread_mutex_lock(&start_time_mutex);
	gettimeofday(&current_time, NULL);
	if (start_time.tv_sec == 0)
		start_time = current_time;
	time = (current_time.tv_sec - start_time.tv_sec) * 1000
		+ (current_time.tv_usec - start_time.tv_usec) / 1000;
	pthread_mutex_unlock(&start_time_mutex);
	return (time);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	if (str[i] == '+')
		i++;
	nbr = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}

void	free_all(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->philos_numbers)
		pthread_mutex_destroy(&(philos[i].forks[i].mutex));
	free(philos[0].forks);
	pthread_mutex_destroy(philos[0].stop->mutex);
	free(philos[0].stop->mutex);
	free(philos[0].stop);
	free(philos);
}
