/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:23:41 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/16 23:22:04 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_pile(int stackc, char **unformated_stack)
{
	int	i;
	int	*pile;

	i = 0;
	pile = malloc(sizeof(*pile) * stackc);
	while (i < stackc)
	{
		pile[i] = ascii_to_int(unformated_stack[i]);
		i++;
	}
	return (pile);
}

// curr_prenb[0] = current_smallest_number, curr_prenb[1] = previous_number
unsigned int	*simplify_pile(int *pile, int pile_size)
{
	unsigned int	*u_pile;
	int				i_j[2];
	long int		curr_prenb[2];
	unsigned int	current_smallest_nb_index;

	u_pile = malloc(sizeof(*u_pile) * pile_size);
	current_smallest_nb_index = 0;
	curr_prenb[1] = (long int)INT_MIN - 1;
	i_j[0] = -1;
	while (++i_j[0] < pile_size)
	{
		i_j[1] = -1;
		curr_prenb[0] = INT_MAX;
		while (++i_j[1] < pile_size)
		{
			if (pile[i_j[1]] <= curr_prenb[0] && pile[i_j[1]] > curr_prenb[1])
			{
				curr_prenb[0] = pile[i_j[1]];
				current_smallest_nb_index = i_j[1];
			}
		}
		curr_prenb[1] = curr_prenb[0];
		u_pile[current_smallest_nb_index] = i_j[0];
	}
	return (u_pile);
}

bool	is_pile_storted(unsigned int *pile, int pile_size)
{
	int	i;

	i = 0;
	if (pile_size > 1)
	{
		while (i < pile_size - 1)
		{
			if (pile[i] > pile[i + 1])
				return (false);
			i++;
		}
	}
	return (true);
}
