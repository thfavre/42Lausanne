/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:58:29 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/11 23:34:16 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_write_board(char *board);
char	*ft_sols_1(int nb);
int		check_duplication_col(char *board);
int		check_board_up(char *rules, char *board);
int		check_board_down(char *rules, char *board);
int		check_board_left(char *rules, char *board);
int		check_board_right(char *rules, char *board);

// checks if the lines match with the rules
// if it is the case, returns 1, otherwise returns 0
int	check_board(char *lines, char *rls)
{
	if ((check_duplication_col(lines))
		&& (check_board_up(rls, lines) && check_board_down(rls, lines))
		&& (check_board_right(rls, lines) && check_board_left(rls, lines)))
	{
		ft_write_board(lines);
		return (1);
	}
	return (0);
}

void	str_add_4char(int start_pos, char *dest, char *src)
{
	int	i;

	i = start_pos;
	while (i < start_pos + 4)
	{
		dest[i] = src[i - start_pos];
		i++;
	}
}

int	looping_bruteforce(char *lines, char *rules, int *nbs)
{
	while (++nbs[0] < 24)
	{
		str_add_4char(0, lines, ft_sols_1(nbs[0]));
		nbs[1] = -1;
		while (++nbs[1] < 24)
		{
			str_add_4char(4, lines, ft_sols_1(nbs[1]));
			nbs[2] = -1;
			while (++nbs[2] < 24)
			{
				str_add_4char(8, lines, ft_sols_1(nbs[2]));
				nbs[3] = -1;
				while (++nbs[3] < 24)
				{
					str_add_4char(12, lines, ft_sols_1(nbs[3]));
					if (check_board(lines, rules))
					{
						free(lines);
						return (1);
					}
				}
			}
		}
	}
	return (0);
}

int	bruteforce(char *rules)
{
	int		nbs[4];
	char	*lines;

	nbs[0] = -1;
	lines = malloc(sizeof(char) * 16);
	if (lines == NULL)
		return (0);
	return (looping_bruteforce(lines, rules, nbs));
}
