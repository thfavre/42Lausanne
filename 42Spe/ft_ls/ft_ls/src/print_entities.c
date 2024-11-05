#include "ft_ls.h"
#include <stdio.h>


void	print_entity_name(const t_entity *entity) {
	const struct dirent *dir_entry = &entity->dir_entry;
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
	t_list	*tmp;
	while (entities && entities->content) {
		const t_entity *entity = (const t_entity *)entities->content;
		print_entity_name(entity);
		tmp = entities;
		entities = entities->next;
		ft_lstdelone(tmp, free);
	}
	ft_printf("\n");
}	
