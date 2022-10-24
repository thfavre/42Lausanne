/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:54:02 by thfavre           #+#    #+#             */
/*   Updated: 2022/09/12 23:36:47 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>



int get_board_value(int *board, int x, int y)
{
	return (board[x + y * 10]);
}

void	move_queen(int *board, int x, int new_y)
{
	board[x] = new_y;
}


// return true if the queen can not be eaten 
// (no others q in the line and diagonals)
int	is_safe(int *board, int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		printf(" i:%d   b:%d   x:%d  y:%d \n", i, board[i],x, y);
		if (i != x && board[i] == y)
			return (0);
		i++;
	}
	printf("---\n");
	i = 0;
	while (i < 9)
	{
		printf(" i:%d   b:%d   x:%d  y:%d \n", i, board[i],x, y);
		if (i != x && board[i] == (y - x) + i && (y - x) + i >= 0)
			return (0);
		if (i != x && board[i] == (x + y - i) && (x + y - i) >= 0)
			return (0);
		i++;
	}
	return (1);
}


int	ft_ten_queens_puzzle(void)
{
	int board[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

	printf(" %d ", is_safe(board, 2, 3));
		
	return (1);
}


int main()
{
	ft_ten_queens_puzzle();
}
