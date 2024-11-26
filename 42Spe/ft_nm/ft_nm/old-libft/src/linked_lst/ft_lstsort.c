/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:42:44 by thfavre           #+#    #+#             */
/*   Updated: 2024/11/26 18:10:03 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_content(t_list *lst)
{
	void	*tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}

static void	sort_pass(t_list *lst, t_compare_fn cmp, int direction,
						bool *modified)
{
	while (lst && lst->next && lst->next->content)
	{
		if (direction * cmp(lst->content, lst->next->content) > 0)
		{
			swap_content(lst);
			*modified = true;
			break ;
		}
		lst = lst->next;
	}
}

void	lst_bubble_sort(t_list *lst, t_compare_fn cmp, bool reverse)
{
	bool	modified;
	int		direction;
	t_list	*start;

	modified = true;
	if (reverse)
		direction = -1;
	else
		direction = 1;
	start = lst;
	while (modified)
	{
		modified = false;
		sort_pass(lst, cmp, direction, &modified);
		lst = start;
	}
}

void	ft_lstsort(t_list *lst, t_compare_fn cmp, bool reverse)
{
	lst_bubble_sort(lst, cmp, reverse);
}

int	ft_lstsort_cmpft_str(const void *lst1, const void *lst2)
{
	return (ft_strcmp((char *)lst1, (char *)lst2));
}
