/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 11:20:23 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/11 23:14:36 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_board_up(char *rules, char *board);
int	check_board_down(char *rules, char *board);
int	check_board_left(char *rules, char *board);
int	check_board_right(char *rules, char *board);

// will read the col x line y of the board
char	read_board(char *board, int x, int y)
{
	return (board[x + y * 4]);
}

int	check_duplication_col(char *board)
{
	int	tab[4];
	int	y;
	int	x;

	x = 0;
	while (x < 4)
	{
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[3] = 0;
		y = 0;
		while (y < 4)
		{
			tab[read_board(board, x, y) - '0' - 1] = 1;
			y++;
		}
		if (!tab[0] || !tab[1] || !tab[2] || !tab[3])
			return (0);
		x++;
	}
	return (1);
}
