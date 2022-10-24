/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:14:46 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/01 13:33:32 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	write_numbers(int c1, int c2, int c3)
{
	put_char(c1);
	put_char(c2);
	put_char(c3);
	if (c1 != '7' || c2 != '8' || c3 != '9' )
	{
		put_char(',');
		put_char(' ');
	}
}	

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '7')
	{
		c2 = c1 + 1;
		while (c2 <= '8')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				write_numbers(c1, c2, c3);
				c3 ++;
			}
			c2++;
		}	
		c1++;
	}
}

/*int main(){
	ft_print_comb();
	}*/
