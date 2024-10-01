/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:42:44 by thfavre           #+#    #+#             */
/*   Updated: 2024/10/01 15:20:10 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_bubble_sort(t_list *lst, compare_fn cmp) {
	bool modified = true;
	t_list *start = lst;
	while (modified) {
		modified = false;
		while (lst && lst->next && lst->next->content) {
			if (cmp(lst->content, lst->next->content) > 0) {
				void *tmp;
				tmp = lst->content;
				lst->content = lst->next->content;
				lst->next->content = tmp;
				modified = true;
				lst = start;
				break;
			}
			lst = lst->next;
		}
	}
	lst = start;
}

void	ft_lstsort(t_list *lst, compare_fn cmp) {
	lst_bubble_sort(lst, cmp);
}
