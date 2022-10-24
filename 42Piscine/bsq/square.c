/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:29:14 by jchapell          #+#    #+#             */
/*   Updated: 2022/09/21 23:37:37 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "prototype.h"
#include <unistd.h>
#include <stdlib.h>

int	bigger_square_from_pos(t_level level, t_point pos)
{
	int	curr_sqr;
	int	x_o;
	int	y_o;

	curr_sqr = 0;
	while (pos.y + curr_sqr < level.data.size
		&& level.map[0][pos.x + curr_sqr] != '\0')
	{
		x_o = 0;
		while (x_o < curr_sqr)
		{
			if (level.map[pos.y + curr_sqr][pos.x + x_o] == level.data.obstacle)
				return (curr_sqr);
			x_o++;
		}
		y_o = 0;
		while (y_o <= curr_sqr)
		{
			if (level.map[pos.y + y_o][pos.x + curr_sqr] == level.data.obstacle)
				return (curr_sqr);
			y_o++;
		}
		curr_sqr++;
	}
	return (curr_sqr);
}

t_square_data	find_bigger_square(t_level level)
{
	t_square_data	bigger_square;
	t_point			testing_square_pos;
	int				tmp;

	bigger_square = (t_square_data){0, {0, 0}};
	testing_square_pos = (t_point){0, 0};
	while (testing_square_pos.y < level.data.size)
	{
		while (level.map[0][testing_square_pos.x])
		{
			tmp = bigger_square_from_pos(level, testing_square_pos);
			if (tmp > bigger_square.size)
			{
				bigger_square.size = tmp;
				bigger_square.pos = testing_square_pos;
			}
			testing_square_pos.x++;
		}
		testing_square_pos.x = 0;
		testing_square_pos.y++;
	}
	return (bigger_square);
}

void	draw_bigger_square(t_level level, int x)
{
	t_square_data	stp;
	int				y;

	stp = find_bigger_square(level);
	x = 0;
	y = 0;
	while (y != level.data.size)
	{
		while (level.map[level.data.size - 1][x])
		{
			if ((x >= stp.pos.x && x < stp.pos.x + stp.size)
				&& (y >= stp.pos.y && y < stp.pos.y + stp.size))
			{	
				write(1, &level.data.square, 1);
			}
			else
				write(1, &level.map[y][x], 1);
				x++;
		}
		write(1, "\n", 1);
		x = 0;
		free(level.map[y]);
		y++;
	}
	free(level.map[y]);
}
