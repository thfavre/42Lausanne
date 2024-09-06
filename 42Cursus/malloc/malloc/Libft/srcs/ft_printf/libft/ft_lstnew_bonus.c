/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:02:51 by ybensegh          #+#    #+#             */
/*   Updated: 2022/11/10 16:16:24 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelement;

	newelement = ft_calloc(1, sizeof(t_list));
	if (newelement == NULL)
		return (NULL);
	newelement->content = content;
	newelement->next = NULL;
	return (newelement);
}
