
#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
		if (lst != NULL)
				{
						lst->content = content;
						lst->next = NULL;
					}
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
			{
					if (!lst->next)
									return (lst);
							lst = lst->next;
								}
		return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
				ft_lstlast(*lst)->next = new;
		else
					*lst = new;
}
