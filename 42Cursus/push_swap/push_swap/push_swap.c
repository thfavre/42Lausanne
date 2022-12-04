
#include "push_swap.h"

t_stack	create_stack(int stackc, char **unformated_stack);
void	push_swap(t_stack stack);

int	main(int argc, char **argv)
{
	if (--argc >= 1)
		push_swap(create_stack(argc, ++argv));

	return (0);
}

int	ascii_to_int(char *str)
{
	int	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		//if (*str < '0' || *str > 9)
		//	return (NULL); //what to return ?
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (nb);
}


int	*create_pile(int stackc, char **unformated_stack)
{
	int	i;
	int	*pile;
	int	*temp_pile_value;

	i = 0;
	pile = malloc(sizeof(*pile) * stackc);
	while (i < stackc)
	{
		pile[i]= ascii_to_int(unformated_stack[i]);
		i++;
	}
	return (pile);
}


t_stack	create_stack(int stackc, char **unformated_stack)
{
	t_stack stack;

	stack.size = stackc;
	stack.pile1 = create_pile(stackc, unformated_stack);
	stack.pile1_size = stackc;
	stack.pile2 = malloc(sizeof(*stack.pile2) * stackc);
	stack.pile2_size = 0;
	return (stack);
}

bool is_pile_storted(int *pile, int pile_size)
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

// TODO make the pile looks like 0 1 2 ,...
void	simplify_pile(int *pile, int pile_size)
{
	int	i;
	int	j;
	int nb;
	int	*smaller_nb;
	int	*simplified_pile;

	simplified_pile = malloc(sizeof(*simplify_pile) * pile_size);
	i = 0;
	while (i < pile_size)
	{
		while (j < pile_size)
		i++;
	}
}

bool	is_1_in_pile_shifted(int *pile, int shifts_bits, int pile_size)
{
	int	i;

	i = 0;
	while (i < pile_size)
		if (((pile[i++] >> shifts_bits) & 1) == 1)
			return (true);
	return (false);
}

bool	is_0_in_pile_shifted(int *pile, int shifts_bits, int pile_size)
{
	int	i;

	i = 0;
	while (i < pile_size)
		if (((pile[i++] >> shifts_bits) & 1) == 0)
			return (true);
	return (false);
}


void	push_swap(t_stack stack)
{
	int	i;

	// if (is_pile_storted(stack.pile1, stack.pile1_size))
	// {
	// 	return ;
	// }
	// simplify pile

	i = 0;
	int j;
	int op_nb = 0;
	int tot = 0; // TODO delete

	//tant que (un nbr de pile1) >> i & 1 == 1
	// while (is_1_in_pile_shifted(stack.pile1, i, stack.pile1_size))
	// {
	while (!is_pile_storted(stack.pile1, stack.pile1_size))
	{
		// tant que (un nbr de pile1) >> i & 1 == 0
		//printf("->%d\n", stack.pile1_size);
		op_nb = 0;
		while (op_nb < stack.size)
		{
			op_nb++;
			// if (top pile1) >> i & 1 == 0
			//printf("->%d\n", stack.pile1_size);
			if (((stack.pile1[0] >> i) & 1) == 0)
					pb(&stack);
			else
				ra(&stack);
				// ra
			tot++;
		}
		// j = -1;
		// printf("\n");
		// while (++j < stack.pile1_size)
		// 	printf("pile1-> %d : %d  \t", j, stack.pile1[j]);
		// j = -1;
		// printf("\n");
		// while (++j < stack.pile2_size)
		// 	printf("pile2-> %d : %d  \t", j, stack.pile2[j]);
		// printf("\n");
		// printf("\nres1 : %d  %d  %d %d\n", stack.pile1[0], stack.pile1[1], stack.pile1[2], stack.pile2_size );
		// // put add pile2 inside pile 1
			while (stack.pile2_size > 0)
				{pa(&stack); tot++;}
			i++;
		//printf("res 2 : %d  %d  %d\n", stack.pile1[0], stack.pile1[1], stack.pile1[2]);
		}
	//}
	printf("\n\nRES\n");
	j = -1;

// 	while (++j < stack.pile1_size - 0)
// 	{
// 		// if (stack.pile1[j] > stack.pile1[j + 1])
// //			printf("WRONG\n");
// 		printf(" %d  \t", stack.pile1[j]);

// 	}
	printf("\nTotal nb of operations : %d\n", tot);
	free(stack.pile1);
	free(stack.pile2);


}

