
#include "push_swap.h"

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
	write(1, "pb\n", 3);
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
		stack->pile1[i] = stack->pile1[i+1];
		i++;
	}
	stack->pile1[stack->pile1_size - 1] = pile1_first_el;
	write(1, "ra\n", 3);
}
