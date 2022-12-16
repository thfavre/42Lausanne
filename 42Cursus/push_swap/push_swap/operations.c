/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:32 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/16 23:17:18 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_stack *stack, enum e_operation new_op);

void	pb(t_stack *stack)
{
	int	i;
	int	pile1_first_el;

	stack->pile1_size--;
	stack->pile2_size++;
	pile1_first_el = stack->pile1[0];
	i = 0;
	while (i <= stack->pile1_size - 1)
	{
		stack->pile1[i] = stack->pile1[i + 1];
		i++;
	}
	i = stack->pile2_size - 1;
	while (i > 0)
	{
		stack->pile2[i] = stack->pile2[i - 1];
		i--;
	}
	stack->pile2[0] = pile1_first_el;
	stack->pile1[stack->pile1_size] = -1;
	write(1, "pb\n", 3);
}

void	pa(t_stack *stack)
{
	int	i;
	int	pile2_first_el;

	stack->pile2_size--;
	stack->pile1_size++;
	pile2_first_el = stack->pile2[0];
	i = 0;
	while (i <= stack->pile2_size - 1)
	{
		stack->pile2[i] = stack->pile2[i + 1];
		i++;
	}
	i = stack->pile1_size - 1;
	while (i > 0)
	{
		stack->pile1[i] = stack->pile1[i - 1];
		i--;
	}
	stack->pile1[0] = pile2_first_el;
	stack->pile2[stack->pile2_size] = -1;
	write(1, "pa\n", 3);
}

void	ra(t_stack *stack)
{
	int	i;
	int	pile1_first_el;

	pile1_first_el = stack->pile1[0];
	i = 0;
	while (i < stack->pile1_size - 1)
	{
		stack->pile1[i] = stack->pile1[i + 1];
		i++;
	}
	stack->pile1[stack->pile1_size - 1] = pile1_first_el;
	write(1, "ra\n", 3);
}
