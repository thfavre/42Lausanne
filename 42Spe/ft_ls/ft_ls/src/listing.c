#include <dirent.h>
#include "ft_ls.h"


t_list *list_entities(const char *dirname, t_options *options, bool is_recursive) {
	DIR *dir = open_directory(dirname);
	if (dir == NULL) return NULL;

	struct dirent *dir_entry;
	t_list *directories = NULL;
	t_list *entities = NULL;
	long total_blocks = 0;

	while ((dir_entry = readdir(dir)) != NULL) {
		process_entity(dirname, dir_entry, &directories, &entities, &total_blocks, options);
	}
	if (!options->U && options->t)
		ft_lstsort(entities, lst_compare_fn_entity_time, options->r);
	else if (!options->U)
		ft_lstsort(entities, lst_compare_fn_entity_str, options->r);

	if (options->l)
		print_entities_long_format(entities, options, total_blocks);
	else
		print_entities(entities, options);

	closedir(dir);
	return directories;
}

void	list_entities_recursively(const char *dirname, t_list *queue, t_options *options) {
	t_list *to_free = NULL;
	if (queue) {
		to_free = queue;
		queue = queue->next;
	}
	ft_printf("%s:\n", dirname);
	t_list	*directories = list_entities(dirname, options, true);
	ft_lstsort(directories, ft_lstsort_cmpft_str, options->r);

	if (!queue)
		queue = directories;
	else {
		t_list *tmp = queue;
		queue = directories;
		ft_lstadd_back(&queue, tmp);
	}
	if (queue) {
		ft_printf("\n");
		list_entities_recursively(queue->content, queue, options);
	}
	if (to_free)
		ft_lstdelone(to_free, free);

}