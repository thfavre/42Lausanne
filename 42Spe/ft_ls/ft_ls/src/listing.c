#include <dirent.h>
#include "ft_ls.h"


t_list *list_entities(const char *dirname, t_options *options) {
    DIR *dir = open_directory(dirname);
    if (dir == NULL) return NULL;

    struct dirent *dir_entry;
    t_list *directories = NULL;
    t_list *entities = NULL;
    long total_blocks = 0;

    while ((dir_entry = readdir(dir)) != NULL) {
        process_entity(dirname, dir_entry, &directories, &entities, &total_blocks, options);
    }

	if (options->t)
    	ft_lstsort(entities, lst_compare_fn_entity_time, options->r);
	else
    	ft_lstsort(entities, lst_compare_fn_entity_str, options->r);

	if (options->l)
		print_entities_long_format(entities, options, total_blocks);
	else
    	print_entities(entities, options);

    closedir(dir);
	ft_lstdelone(directories, free);
    return directories;
}

void	list_entities_recursively(const char *dirname, t_list *queue, t_options *options) {
	// t_list *tmp;
	if (queue) {
		// tmp = queue;
		queue = queue->next;
		// ft_lstdelone(tmp, free);
	}
	ft_printf("%s:\n", dirname);
	t_list	*directories = list_entities(dirname, options);
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
	// ft_lstdelone(directories, free);
}