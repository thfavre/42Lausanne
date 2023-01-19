/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:30 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/11 13:00:06 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	correct_input(int input_nb, char **input);
t_stack	create_stack(int stackc, char **unformated_stack);

int	main(int argc, char **argv)
{
	char	**input;
	int		input_nb;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		input_nb = 0;
		while (input[input_nb])
			input_nb++;
	}
	else
	{
		input = argv + 1;
		input_nb = argc - 1;
	}
	if (!correct_input(input_nb, input))
		write(2, "Error\n", 6);
	else if (input_nb < 6)
		small_push_swap(create_stack(input_nb, input));
	else
		big_push_swap(create_stack(input_nb, input));
	exit(1);
}

bool	correct_input(int input_nb, char **input)
{
	int		i;
	int		j;

	i = 0;
	while (i < input_nb)
		if (!is_str_integer_number(input[i++]))
			return (false);
	i = 0;
	while (i < input_nb)
	{
		j = i + 1;
		while (j < input_nb)
			if (ascii_to_int(input[i]) == ascii_to_int(input[j++]))
				return (false);
		i++;
	}
	return (true);
}

t_stack	create_stack(int stackc, char **unformated_stack)
{
	t_stack			stack;
	int				*int_pile1;
	unsigned int	*u_int_pile1;

	stack.size = stackc;
	int_pile1 = create_pile(stackc, unformated_stack);
	u_int_pile1 = simplify_pile(int_pile1, stackc);
	free(int_pile1);
	stack.pile1 = u_int_pile1;
	stack.pile1_size = stackc;
	stack.pile2 = malloc(sizeof(*stack.pile2) * stackc);
	stack.pile2_size = 0;
	stack.operations = NULL;
	stack.operations_numbers = 0;
	return (stack);
}
