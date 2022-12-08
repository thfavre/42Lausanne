/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:30 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/08 18:15:28 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	create_stack(int stackc, char **unformated_stack);
void	small_push_swap(t_stack stack);
void	big_push_swap(t_stack stack);

int	main(int argc, char **argv)
{
	int	i;

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
		small_push_swap(create_stack(--argc, ++argv));
	else
		big_push_swap(create_stack(--argc, ++argv));
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
	return (stack);
}

char	*sortthree(t_stack *a)
{
	char	*mark;
	char	*moves;

	mark = stack_getmark(a);
	if (!ft_strncmp(mark, "1 2 3", 5))
		moves = ft_strdup("");
	else if (!ft_strncmp(mark, "1 3 2", 5))
		moves = ft_strdup("rra\nsa\n");
	else if (!ft_strncmp(mark, "2 1 3", 5))
		moves = ft_strdup("sa\n");
	else if (!ft_strncmp(mark, "2 3 1", 5))
		moves = ft_strdup("rra\n");
	else if (!ft_strncmp(mark, "3 1 2", 5))
		moves = ft_strdup("ra\n");
	else
		moves = ft_strdup("ra\nsa\n");
	free(mark);
	return (moves);
}
// will sort less than 6 numbers
void	small_push_swap(t_stack stack)
{


	free(stack.pile1);
	free(stack.pile2);
}

// will sort more than 5 numbers
void	big_push_swap(t_stack stack)
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
}

