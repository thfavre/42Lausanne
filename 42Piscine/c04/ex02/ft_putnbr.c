/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 01:40:24 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/06 03:29:33 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nb(int nb)
{
	char	c;

	c = nb + '0';
	write(1, &c, 1);
}

void	random_function(int nb)
{
	int	pow;
	int	pow2;
	int	nb2;

	nb2 = nb;
	pow = 0;
	while (nb2 >= 10)
	{
		nb2 /= 10;
		pow++;
	}
	while (pow >= 0)
	{
		pow2 = pow;
		nb2 = 1;
		while (pow2 > 0)
		{
			nb2 *= 10;
			pow2--;
		}
		write_nb(nb / nb2);
		nb %= nb2;
		pow--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		random_function(nb);
	}
}

//int main() { ft_putnbr(-2147483646);  }
