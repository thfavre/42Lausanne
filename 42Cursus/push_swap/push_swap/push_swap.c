/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:30 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/09 16:15:15 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_stack(int stackc, char **unformated_stack);


int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 1;
	while (i < argc)
		if (!is_str_integer_number(argv[i++]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	if (argc == 2)
		return (0);
	if (argc <=5)
		stack = small_push_swap(create_stack(--argc, ++argv));
	else
		stack =  big_push_swap(create_stack(--argc, ++argv));
	print_operations(stack);
	return (0);
}

t_stack	create_stack(int stackc, char **unformated_stack)
{
	t_stack			stack;
	int				*int_pile1;
	unsigned int	*u_int_pile1;

	stack.size = stackc;
	int_pile1 = create_pile(stackc, unformated_stack);
	// check pile validiyy (no dup, ...)
	u_int_pile1 = simplify_pile(int_pile1, stackc);
	stack.pile1 = u_int_pile1;
	stack.pile1_size = stackc;
	stack.pile2 = malloc(sizeof(*stack.pile2) * stackc);
	stack.pile2_size = 0;
	stack.operations = NULL;
	stack.operations_numbers = 0;
	return (stack);
}

