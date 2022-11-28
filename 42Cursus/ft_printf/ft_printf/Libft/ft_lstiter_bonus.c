/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:22:06 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/11 20:44:20 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_next;

	if (lst)
	{
		lst_next = lst;
		while (lst_next != NULL)
		{
			(*f)(lst_next->content);
			lst_next = lst_next->next;
		}
	}
}
