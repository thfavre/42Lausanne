/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinebenseghir <marvin@42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:46:41 by yassinebenseg     #+#    #+#             */
/*   Updated: 2022/11/11 21:50:49 by yassinebenseg    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelement;

	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newelement = ft_lstnew((*f)(lst->content));
		if (newelement == NULL)
		{
			ft_lstclear(&newelement, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newelement);
		lst = lst->next;
	}
	return (newlst);
}
