/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:39:18 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/13 14:04:51 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortthree(unsigned int *pile)
{
	if (pile[0] == 0 && pile[1] == 1 && pile[2] == 2)
		write(1, "\n", 0);
	// convert all the lines below like the line abow
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
	// if (!ft_strncmp(mark, "1 2 3", 5))
	// 	moves = ft_strdup("");
	// else if (!ft_strncmp(mark, "1 3 2", 5))
	// 	moves = ft_strdup("rra\nsa\n");
	// else if (!ft_strncmp(mark, "2 1 3", 5))
	// 	moves = ft_strdup("sa\n");
	// else if (!ft_strncmp(mark, "2 3 1", 5))
	// 	moves = ft_strdup("rra\n");
	// else if (!ft_strncmp(mark, "3 1 2", 5))
	// 	moves = ft_strdup("ra\n");
	// else
	// 	moves = ft_strdup("ra\nsa\n");
	// free(mark);
	// return (moves);
}
// will sort less than 6 numbers
t_stack	small_push_swap(t_stack stack)
{
	if (stack.pile1_size == 2)
	{
		if (stack.pile1[0] > stack.pile1[1])
			write(1, "ra\n", 3);
	}
	else if (stack.pile1_size == 3)
		sortthree(stack.pile1);
	else if (stack.pile1_size == 4)
	{
		while (stack.pile1[0] != 3)
			ra(&stack);
		pb(&stack);
		sortthree(stack.pile1);
		pa(&stack);
		write(1, "ra\n", 3);

	}

	free(stack.pile1);
	free(stack.pile2);
	return (stack);
}

// will sort more than 5 numbers
t_stack	big_push_swap(t_stack stack)
{
	int	i;

	i = 0;
	int op_nb = 0;
	int tot = 0; // TODO delete
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
			tot++;
		}
		while (stack.pile2_size > 0)
			{pa(&stack); tot++;}
		i++;
	}
	// TODO delete this tester
	// printf("\n\nRES\n");
	// int j;
	// j = -1;
	// while (++j < stack.pile1_size - 0)
	// {
	// 	if (j + 1 < stack.pile1_size && stack.pile1[j] > stack.pile1[j + 1])
	// 		printf("\n\nWRONG %d, %d, %d\n\n", j, stack.pile1[j], stack.pile1[j + 1]);
	// 	printf("\t%d", stack.pile1[j]);

 	// }
	// printf("\nTotal nb of operations : %d\n", tot);
	free(stack.pile1);
	free(stack.pile2);
	return (stack);
}

