/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:35 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/21 15:44:22 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ascii_to_int(char *str)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (sign * nb);
}

bool	is_str_integer_number(char *str)
{
	long	nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '\0')
		return (false);
	while (*str)
	{
		nb *= 10;
		nb += *str - '0';
		if (*str < '0' || *str > '9' || \
			nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (false);
		str++;
	}
	return (true);
}
