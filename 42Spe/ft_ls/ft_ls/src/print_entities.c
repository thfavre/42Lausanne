#include "ft_ls.h"
#include <stdio.h>
#include <errno.h>
 #include <pwd.h>
#include <grp.h>
#include <time.h>

void	print_entity_name(const t_entity *entity) {
	const struct dirent *dir_entry = &entity->dir_entry;//(const struct dirent *)all_dirents->content->dir_entry;
	if (dir_entry->d_type == DT_DIR)
		ft_printf(BOLD_BLUE);
	else if (dir_entry->d_type == DT_LNK)
		ft_printf(BOLD_CYAN);
	else
		ft_printf(COLOR_RESET);

	ft_printf("%s\t", dir_entry->d_name);
	ft_printf(COLOR_RESET);
}


void print_entities(t_list *entities, t_options *options) {
    // ft_lstsort(all_dirents, lst_compare_fn_dirent_str, options->r);
        // ft_printf("COLOR_RESET\n");

    while (entities && entities->content) {
        const t_entity *entity = (const t_entity *)entities->content;
		print_entity_name(entity);
        // const struct dirent *dir_entry = &entity->dir_entry;//(const struct dirent *)all_dirents->content->dir_entry;
        // if (dir_entry->d_type == DT_DIR)
        //     ft_printf(BOLD_BLUE);
        // else if (dir_entry->d_type == DT_LNK)
        //     ft_printf(BOLD_CYAN);
        // else
        //     ft_printf(COLOR_RESET);

        // ft_printf("%s\t", dir_entry->d_name);
        // ft_printf(COLOR_RESET);
        entities = entities->next;
    }
    ft_printf("\n");
}
