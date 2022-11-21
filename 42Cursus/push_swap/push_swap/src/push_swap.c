
#include "../includes/push_swap.h"

void	push_swap(int stackc, char **unforated_stack);

int	main(int argc, char **argv)
{
	if (--argc >= 1)
		push_swap(++argv);
	
	return (0);
}


int	*create_pile(int stackc, char **unformated_stack)
{
	int	i;
	int	*pile;

	i = 0;
	pile = malloc(sizeof(*pile) * stackc);
	while (i < stackc)
	{
		pile[i] = 

		i++;
	}
}

void	push_swap(int stackc, char **unformated_stack)
{
	t_stack	stack;
	
	stack.size = stackc;
	stack.pile1 = create_pile(unforated_stack);


}
