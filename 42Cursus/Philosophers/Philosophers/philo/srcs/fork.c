/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:43:17 by thfavre           #+#    #+#             */
/*   Updated: 2023/05/22 14:13:56 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	if (!fork->is_taken)
	{
		fork->is_taken = true;
		pthread_mutex_unlock(&fork->mutex);
		logs("\033[1;36mhas taken a fork\033[0m", philo, false);
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
