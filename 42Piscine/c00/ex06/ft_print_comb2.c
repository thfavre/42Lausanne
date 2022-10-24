/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:02:39 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/01 11:04:09 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	convert_int_to_char_and_write(int nb)
{
	char	c1;
	char	c2;

	if (nb <= 9)
	{
		c2 = '0' + nb;
		c1 = '0';
	}
	else
	{
		c1 = '0' + nb / 10;
		c2 = '0' + nb % 10;
	}
	put_char(c1);
	put_char(c2);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (x <= 98)
	{
		while (y <= 99)
		{
			convert_int_to_char_and_write(x);
			put_char(' ');
			convert_int_to_char_and_write(y);
			y++;
			if (x < 98 || y <= 98)
			{
				put_char(',');
				put_char(' ');
			}
		}
		x++;
		y = x +1;
	}
}
/*int	main()
{
	ft_print_comb2();
}*/
