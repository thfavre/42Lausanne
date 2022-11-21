
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

int	ft_atoi(const char *str);

typedef struct	s_stack
{
	int	size;
	int	*pile1;
	int	pile1_size;
	int	*pile2;
	int	pile2_size;
	int	temp1;
	int	temp2;
}		t_stack;


#endif
