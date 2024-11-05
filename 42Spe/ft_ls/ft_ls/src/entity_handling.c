#include "ft_ls.h"


void process_entity(const char *dirname, struct dirent *dir_entry, t_list **directories, t_list **entities, long *total_blocks, t_options *options) {
	if (!(options->a || options->A) && dir_entry->d_name[0] == '.') return;
	if (options->A && (ft_strcmp(dir_entry->d_name, ".") == 0 || ft_strcmp(dir_entry->d_name, "..") == 0)) return; 
	char path[1024] = { 0 };
	ft_strlcat(path, dirname, 1024);
	ft_strlcat(path, "/", 1024);
	ft_strlcat(path, dir_entry->d_name, 1024);
	if (options->R && dir_entry->d_type == DT_DIR && strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0)
		handle_directory(path, directories);
		
	struct stat entity_stat;
	t_entity *entity = malloc(sizeof(t_entity));
	if (handle_file(path, &entity_stat, total_blocks) == 0) {
		entity->dir_entry = *dir_entry;
		entity->entity_stat = entity_stat;
		ft_lstadd_back(entities, ft_lstnew(entity));
	}
}