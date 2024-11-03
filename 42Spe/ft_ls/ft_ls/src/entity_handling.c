#include "ft_ls.h"
#include <stdio.h>
#include <errno.h>
 #include <pwd.h>
#include <grp.h>
#include <time.h>




void process_entity(const char *dirname, struct dirent *dir_entry, t_list **directories, t_list **entities, long *total_blocks, t_options *options) {
    if (!options->a && dir_entry->d_name[0] == '.') return;

    char path[1000] = { 0 };
    ft_strlcat(path, dirname, 1000);
    ft_strlcat(path, "/", 1000);
    ft_strlcat(path, dir_entry->d_name, 1000);

    if (dir_entry->d_type == DT_DIR && strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
        handle_directory(path, directories);
    }

    struct stat entity_stat;
    // t_entity entity;
    t_entity *entity = malloc(sizeof(t_entity)); // TODO free
    if (handle_file(path, &entity_stat, total_blocks) == 0) {
        entity->dir_entry = *dir_entry;
        entity->entity_stat = entity_stat;
        ft_lstadd_back(entities, ft_lstnew(entity));
    } // ? TODO something on error?
}
