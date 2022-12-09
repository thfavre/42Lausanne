/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:32 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/09 16:47:55 by thfavre          ###   ########.fr       */
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

	// shift all element (except the first one up)
	i = 0;
	while (i <= stack->pile1_size - 1)
	{
		stack->pile1[i] = stack->pile1[i+1];
		i++;
	}
	//stack->pile1 = new_pile1;
	// shift all el (expect the last one) down
	i = stack->pile2_size - 1;
	while (i > 0)
	{
		stack->pile2[i] = stack->pile2[i - 1];
		i--;
	}
	stack->pile2[0] = pile1_first_el;
	stack->pile1[stack->pile1_size] = -1;
	//write(1, "pb\n", 3);
	add_operation(stack, PB);
}

void	pa(t_stack *stack)
{
	int	i;
	int	pile2_first_el;

	stack->pile2_size--;
	stack->pile1_size++;
	pile2_first_el = stack->pile2[0];

	// shift all element (except the first one up)
	i = 0;
	while (i <= stack->pile2_size - 1)
	{
		stack->pile2[i] = stack->pile2[i+1];
		i++;
	}
	//stack->pile1 = new_pile1;
	// shift all el (expect the last one) down
	i = stack->pile1_size - 1;
	while (i > 0)
	{
		stack->pile1[i] = stack->pile1[i - 1];
		i--;
	}
	stack->pile1[0] = pile2_first_el;
	stack->pile2[stack->pile2_size] = -1;
	//write(1, "pa\n", 3);
	add_operation(stack, PA);
}

void	ra(t_stack *stack)
{
	int	i;
	int	pile1_first_el;

	pile1_first_el = stack->pile1[0];
	i = 0;
	while (i < stack->pile1_size - 1)
	{
		stack->pile1[i] = stack->pile1[i+1];
		i++;
	}
	stack->pile1[stack->pile1_size - 1] = pile1_first_el;
	add_operation(stack, RA);
	//write(1, "ra\n", 3);
}

void	add_operation(t_stack *stack, enum e_operation new_op)
{
	enum e_operation	*new;
	size_t				i;

	new = malloc(sizeof(*new) * (stack->operations_numbers + 1));
	i = 0;
	while (i < stack->operations_numbers)
	{
		new[i] = stack->operations[i];
		i++;
	}
	stack->operations_numbers++;
	new[i++] = new_op;
	free(stack->operations);
	stack->operations = new;
}

void	print_operations(t_stack stack)
{
	size_t	i;

	i = 0;
	while (i < stack.operations_numbers)
	{
		if (i < stack.operations_numbers && stack.operations[i] == PB && stack.operations[i + 1] == PA)
		{
			stack.operations[i] = 99;
			stack.operations[i + 1] = 99;
		}
		if (i < stack.operations_numbers && stack.operations[i] == PA && stack.operations[i + 1] == PB)
		{
			stack.operations[i] = 99;
			stack.operations[i + 1] = 99;
		}
		i++;

	}
	i = 0;
	while (i < stack.operations_numbers)
	{
		if (stack.operations[i] == PB)
			write(1, "pb\n", 3);
		else if (stack.operations[i] == PA)
			write(1, "pa\n", 3);
		else if (stack.operations[i] == RA)
			write(1, "ra\n", 3);
		else if (stack.operations[i] == RRA)
			write(1, "rra\n", 4);
		else if (stack.operations[i] == SA)
			write(1, "sa\n", 3);
		//else if (stack.operations[i] == SA)
		// 	write(1, "sa\n", 3);
		// else if (stack.operations[i] == SA)
		// 	write(1, "sa\n", 3);
		// else if (stack.operations[i] == SA)
		// 	write(1, "sa\n", 3);
		// else if (stack.operations[i] == SA)
		// 	write(1, "sa\n", 3);
		// else if (stack.operations[i] == SA)
		// 	write(1, "sa\n", 3);
		// else if (stack.operations[i] == SA)
		// 	write(1, "sa\n", 3);
		i++;
	}
}
