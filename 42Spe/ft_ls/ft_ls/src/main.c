#include "ft_ls.h"
#include "libft.h"

int char_compare(const void *a, const void *b) {
    return (ft_strcmp(a, b));
}

// int ft_lstsort_cmpft_str(const void *lst1, const void *lst2) {
// 	// char *str1 = (char *) ((t_list *)lst1)->content;
// 	return (ft_strcmp((char *)lst1, (char *)lst2));
// }

void	multiple_src_paths(t_options *options) {
	ft_lstsort(options->paths, ft_lstsort_cmpft_str, options->r);
	while (options->paths) {
		if (options->R)
			list_files_recursively(options->paths->content, NULL, options);
		else {
			ft_printf("%s:\n", options->paths->content);
			list_files(options->paths->content, options);
		}
		options->paths = options->paths->next;
		// ft_printf("\n");
		if (options->paths)
			ft_printf("\n");
	}
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
	if (options.paths->next)
		multiple_src_paths(&options);
	else { // TODO put in function
		if (options.R)
			list_files_recursively(options.paths->content, NULL, &options);
		else
			list_files(options.paths->content, &options);
	}
	return 0;
}
