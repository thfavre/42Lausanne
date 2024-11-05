#include "ft_ls.h"


void	process_paths(t_options *options) {
	t_list	*tmp;

	ft_lstsort(options->paths, ft_lstsort_cmpft_str, options->r);
	bool is_multiple_src_paths = options->paths->next != NULL;
	while (options->paths) {
		if (options->R)
			list_entities_recursively(options->paths->content, NULL, options);
		else {
			if (is_multiple_src_paths)
				ft_printf("%s:\n", options->paths->content);
			list_entities(options->paths->content, options);
		}
		tmp = options->paths;
		options->paths = options->paths->next;
		// ft_lstdelone(tmp, free);
		free(tmp);
		if (options->paths)
			ft_printf("\n");
	}
}