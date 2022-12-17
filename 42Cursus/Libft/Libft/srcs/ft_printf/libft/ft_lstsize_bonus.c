/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:50:47 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/10 23:06:52 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next_element;

	i = 0;
	next_element = lst;
	while (next_element != NULL)
	{
		next_element = next_element->next;
		i++;
	}
	return (i);
}
