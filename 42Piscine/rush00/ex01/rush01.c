/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:48:31 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/03 14:45:23 by ereymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_character(int currx, int curry, int x, int y)
{
	if (currx == 0 && curry == 0)
		ft_putchar('/');
	else if (currx == x -1 && curry == y -1 && currx > 0)
		ft_putchar('/');
	else if (currx == 0 && curry == y -1)
		ft_putchar('\\');
	else if (currx == x -1 && curry == 0)
		ft_putchar('\\');
	else if (currx == 0 || curry == 0 || currx == x -1 || curry == y -1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

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
			write_character(currx, curry, x, y);
			currx++;
		}
		ft_putchar('\n');
		curry++;
	}
}
