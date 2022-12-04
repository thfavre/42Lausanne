#include "push_swap.h"

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

// TODO make the pile looks like 0 1 2 ,...
unsigned int	*simplify_pile(int *pile, int pile_size)
{
	unsigned int	*u_pile;
	int				i;
	int				current_smallest_nb;
	int				previous_nb;
	unsigned int	current_smallest_nb_index;

	u_pile = malloc(sizeof(*u_pile) * pile_size);

	current_smallest_nb_index = 0;
	previous_nb = INT_MIN;
	i = 0;
	int j;
	while (i < pile_size)
	{
		j = 0;
		current_smallest_nb = INT_MAX;
		while (j < pile_size)
		{
			if (pile[j] <= current_smallest_nb && pile[j] > previous_nb) // TEST WITH INT MIN AND MAX
			{
				current_smallest_nb = pile[j];
				current_smallest_nb_index = j;
			}
			j++;
		}
		//printf("current_smallest_nb %d\n", current_smallest_nb);
		previous_nb = current_smallest_nb;
		u_pile[current_smallest_nb_index] = i;
		// find the index of the samller nb that is bigger than the previous smaller

		i++;
	}
	// i = 0;
	// while (i < pile_size)
	// 	printf("=%d ", u_pile[i++]);
	free(pile);
	return (u_pile);
}

bool is_pile_storted(unsigned int *pile, int pile_size)
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
