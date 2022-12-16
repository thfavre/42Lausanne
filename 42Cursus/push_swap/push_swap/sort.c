/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:39:18 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/16 22:02:33 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(unsigned int *pile)
{
	if (pile[0] == 0 && pile[1] == 1 && pile[2] == 2)
		write(1, "\n", 0);
	else if (pile[0] == 0 && pile[1] == 1 && pile[2] == 2)
		write(1, "", 0);
	else if (pile[0] == 0 && pile[1] == 2 && pile[2] == 1)
		write(1, "rra\nsa\n", 7);
	else if (pile[0] == 1 && pile[1] == 0 && pile[2] == 2)
		write(1, "sa\n", 3);
	else if (pile[0] == 1 && pile[1] == 2 && pile[2] == 0)
		write(1, "rra\n", 4);
	else if (pile[0] == 2 && pile[1] == 0 && pile[2] == 1)
		write(1, "ra\n", 3);
	else
		write(1, "ra\nsa\n", 6);
}

void	sort_four_and_five(t_stack stack)
{
	if (is_pile_storted(stack.pile1, stack.pile1_size))
		return ;
	while (stack.pile1[0] != 3)
		ra(&stack);
	pb(&stack);
	if (stack.pile1_size == 3)
	{
		sort_three(stack.pile1);
		pa(&stack);
	}
	else
	{
		while (stack.pile1[0] != 4)
			ra(&stack);
		pb(&stack);
		sort_three(stack.pile1);
		pa(&stack);
		pa(&stack);
		ra(&stack);
	}
	ra(&stack);
}

// will sort less than 6 numbers
t_stack	small_push_swap(t_stack stack)
{
	if (stack.pile1_size == 2)
	{
		if (stack.pile1[0] > stack.pile1[1])
			ra(&stack);
	}
	else if (stack.pile1_size == 3)
		sort_three(stack.pile1);
	else
		sort_four_and_five(stack);
	free(stack.pile1);
	free(stack.pile2);
	return (stack);
}

// will sort more than 5 numbers
t_stack	big_push_swap(t_stack stack)
{
	int	i;
	int	op_nb;

	i = 0;
	op_nb = 0;
	while (!is_pile_storted(stack.pile1, stack.pile1_size))
	{
		op_nb = 0;
		while (op_nb < stack.size)
		{
			op_nb++;
			if (((stack.pile1[0] >> i) & 1) == 0)
				pb(&stack);
			else
				ra(&stack);
		}
		while (stack.pile2_size > 0)
			pa(&stack);
		i++;
	}
	free(stack.pile1);
	free(stack.pile2);
	return (stack);
}
