/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:54:13 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/11 21:57:39 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_next;
	t_list	*lst_current;

	if (lst)
	{
		lst_next = lst[0];
		while (lst_next != NULL)
		{
			lst_current = lst_next;
			(*del)(lst_current->content);
			lst_next = lst_next->next;
			free(lst_current);
		}
		lst[0] = NULL;
	}
}
