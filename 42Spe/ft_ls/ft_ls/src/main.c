#include "ft_ls.h"
#include "libft.h"

int char_compare(const void *a, const void *b) {
    return (ft_strcmp(a, b));
}

int main(int ac, char **av) {
	// t_list *lst = ft_lstnew("C");
	// lst->next = ft_lstnew("b");
	// lst->next->next = ft_lstnew("a");
	// ft_lstsort(lst, ft_strcmp);
	// ft_printf("el ->%s[\n", lst->content);
	// ft_printf("el ->%s[\n", lst->next->content);
	// ft_printf("el ->%s[\n", lst->next->next->content);

	t_options options = parse_options(ac, av);


	list_files(".", &options);
	// list_files_recursively(".", NULL, &options);
	return 0;
}
