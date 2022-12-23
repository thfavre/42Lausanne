/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:37 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/21 17:54:34 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	;

typedef struct s_stack
{
	int					size;
	unsigned int		*pile1;
	int					pile1_size;
	unsigned int		*pile2;
	int					pile2_size;
	enum e_operation	*operations;
	unsigned int		operations_numbers;
}		t_stack;

/* utils.c */
int				ascii_to_int(char *str);
bool			is_str_integer_number(char *str);
/* pile */
int				*create_pile(int stackc, char **unformated_stack);
bool			is_pile_storted(unsigned int *pile, int pile_size);
unsigned int	*simplify_pile(int *pile, int pile_size);
/* operations.c */
void			pb(t_stack *stack);
void			pa(t_stack *stack);
void			ra(t_stack *stack);
/* sort.c */
t_stack			small_push_swap(t_stack stack);
t_stack			big_push_swap(t_stack stack);
#endif
