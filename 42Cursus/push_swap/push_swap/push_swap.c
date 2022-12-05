
#include "push_swap.h"

t_stack	create_stack(int stackc, char **unformated_stack);
void	push_swap(t_stack stack);

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
	if (argc > 2)
		push_swap(create_stack(--argc, ++argv));

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

void	push_swap(t_stack stack)
{
	int	i;

	// if (!is_pile_storted(stack.pile1, stack.pile1_size))
	// 	{}
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

