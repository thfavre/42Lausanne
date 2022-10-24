/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:48:31 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 13:22:19 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	currx;
	int	curry;

	curry = 0;
	while (curry < y)
	{
		currx = 0;
		while (currx < x)
		{
			if ((currx == 0 || currx == x -1) && (curry == 0 || curry == y -1))
				ft_putchar('o');
			else if (curry == 0 || curry == y -1)
				ft_putchar('-');
			else if (currx == 0 || currx == x -1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			currx++;
		}
		ft_putchar('\n');
		curry++;
	}
}
