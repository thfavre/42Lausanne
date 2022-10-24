/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:30:32 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/15 00:11:43 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_strs_to_tab.c"
#include <unistd.h>
#include "ft_stock_str.h"

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

void	put_str(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		put_str(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		i++;
	}
}
