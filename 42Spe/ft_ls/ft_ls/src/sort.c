#include "ft_ls.h"
#include "libft.h"

// // typedef int (*compare_fn)(const void *, const void *);

// t_list	*lst_bubble_sort(t_list *lst, compare_fn cmp) {
// 	bool modified = true;
// 	t_list *start = lst;
// 	while (modified) {
// 		modified = false;
// 		while (lst->next && lst->next->content) {
// 			if (cmp(lst->content, lst->next->content) > 0) {
// 				void *tmp;
// 				tmp = lst->content;
// 				lst->content = lst->next->content;
// 				lst->next->content = tmp;
// 				modified = true;
// 				lst = start;
// 				break;
// 			}
// 			lst = lst->next;
// 		}
// 	}
// 	lst = start;
// }
