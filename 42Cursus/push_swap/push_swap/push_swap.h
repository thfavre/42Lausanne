
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
#include <limits.h>
int	ft_atoi(const char *str);

typedef struct	s_stack
{
	int	size;
	unsigned int	*pile1;
	int	pile1_size;
	unsigned int	*pile2;
	int	pile2_size;
	int	temp1;
	int	temp2;
}		t_stack;

/* utils.c */
int				ascii_to_int(char *str);
/* pile */
int				*create_pile(int stackc, char **unformated_stack);
bool			is_pile_storted(unsigned int *pile, int pile_size);
unsigned int	*simplify_pile(int *pile, int pile_size);
/* operations.c */
void			pb(t_stack *stack);
void			pa(t_stack *stack);
void			ra(t_stack *stack);
#endif
