/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:45:44 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/11 22:56:34 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	read_board(char *board, int x, int y);

// returns 1 if the given board is matching with the rules
// from the vue of col up (top to bottom)
int	check_board_up(char *rules, char *board)
{
	int		x;
	int		y;
	char	current_height;
	int		rules_index;
	int		tower_seen_nb;

	rules_index = 0;
	x = -1;
	while (++x < 4)
	{
		y = -1;
		tower_seen_nb = 0;
		current_height = 0;
		while (++y < 4)
		{
			if (read_board(board, x, y) > current_height)
			{
				current_height = read_board(board, x, y);
				tower_seen_nb++;
			}
		}
		if (tower_seen_nb != rules[2 * rules_index++] - '0')
			return (0);
	}
	return (1);
}

// returns 1 if the given board is matching with the rules
// from the vue of col down (bottom to top)
int	check_board_down(char *rules, char *board)
{
	int		x;
	int		y;
	char	current_height;
	int		rules_index;
	int		tower_seen_nb;

	rules_index = 4;
	x = -1;
	while (++x < 4)
	{
		y = 4;
		tower_seen_nb = 0;
		current_height = 0;
		while (--y >= 0)
		{
			if (read_board(board, x, y) > current_height)
			{
				current_height = read_board(board, x, y);
				tower_seen_nb++;
			}
		}
		if (tower_seen_nb != rules[2 * rules_index++] - '0')
			return (0);
	}
	return (1);
}

// returns 1 if the given board is matching with the rules
// from the vue of col left (left to right)
int	check_board_left(char *rules, char *board)
{
	int		x;
	int		y;
	char	current_height;
	int		rules_index;
	int		tower_seen_nb;

	rules_index = 8;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		tower_seen_nb = 0;
		current_height = 0;
		while (++x < 4)
		{
			if (read_board(board, x, y) > current_height)
			{
				current_height = read_board(board, x, y);
				tower_seen_nb++;
			}
		}
		if (tower_seen_nb != rules[2 * rules_index++] - '0')
			return (0);
	}
	return (1);
}

// returns 1 if the given board is matching with the rules
// from the vue of col right (right to left)
int	check_board_right(char *rules, char *board)
{
	int		x;
	int		y;
	char	current_height;
	int		rules_index;
	int		tower_seen_nb;

	rules_index = 12;
	y = -1;
	while (++y < 4)
	{
		x = 4;
		tower_seen_nb = 0;
		current_height = 0;
		while (--x >= 0)
		{
			if (read_board(board, x, y) > current_height)
			{
				current_height = read_board(board, x, y);
				tower_seen_nb++;
			}
		}
		if (tower_seen_nb != rules[2 * rules_index++] - '0')
			return (0);
	}
	return (1);
}
