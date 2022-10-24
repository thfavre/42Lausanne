/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereymond <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:36:18 by ereymond          #+#    #+#             */
/*   Updated: 2022/09/03 14:43:48 by ereymond         ###   ########.fr       */
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
			if (currx == 0 && (curry == 0 || curry == y -1))
				ft_putchar('A');
			else if (currx == x -1 && (curry == 0 || curry == y -1))
				ft_putchar('C');
			else if (curry == 0 || curry == y -1)
				ft_putchar('B');
			else if (currx == 0 || currx == x -1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			currx++;
		}
		ft_putchar('\n');
		curry++;
	}
}
