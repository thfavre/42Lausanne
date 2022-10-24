/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:01 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/13 02:16:35 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	unsigned int	t;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	t = 0;
	while (t * t <= (unsigned int)nb)
	{
		t++;
	}
	return (t);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt_nb;

	i = 2;
	if (nb <= 1)
		return (0);
	sqrt_nb = ft_sqrt(nb);
	while (i <= sqrt_nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb == 2147483647)
		return (2147483647);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}

//int main() { printf("%d", ft_find_next_prime(14));  }
