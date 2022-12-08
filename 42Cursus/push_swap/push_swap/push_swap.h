/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:47:37 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/08 16:47:38 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	int				size;
	unsigned int	*pile1;
	int				pile1_size;
	unsigned int	*pile2;
	int				pile2_size;
	char			**operations;
}		t_stack;

/* utils.c */
int				ascii_to_int(char *str);
bool	is_str_integer_number(char *str);
/* pile */
int				*create_pile(int stackc, char **unformated_stack);
bool			is_pile_storted(unsigned int *pile, int pile_size);
unsigned int	*simplify_pile(int *pile, int pile_size);
/* operations.c */
void			pb(t_stack *stack);
void			pa(t_stack *stack);
void			ra(t_stack *stack);
#endif
