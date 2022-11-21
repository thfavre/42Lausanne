
#include "../includes/push_swap.h"

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
	stack.pile2 = malloc(sizeof(int) * stackc);
	stack.pile2_size = 0;
	return (stack);
}

void	push_swap(t_stack stack)
{
	
}

