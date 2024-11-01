// sorting_utils.c
#include "ft_ls.h"

int lst_compare_fn_entity_str(const void *entity1, const void *entity2) {
    const struct dirent *d1 = &((const struct s_entity *)entity1)->dir_entry;
    const struct dirent *d2 = &((const struct s_entity *)entity2)->dir_entry;
    return (ft_strcmp(d1->d_name, d2->d_name));
}

int lst_compare_fn_entity_time(const void *entity1, const void *entity2) {
    // entity->entity_stat.st_mtime
    const struct stat *entity_stat1 = &((const struct s_entity *)entity1)->entity_stat;
    const struct stat *entity_stat2 = &((const struct s_entity *)entity2)->entity_stat;
    // if (entity_stat2->st_mtime == entity_stat1->st_mtime) {
    //     return lst_compare_fn_entity_str(entity1, entity2);
    // }
    return (entity_stat1->st_mtime < entity_stat2->st_mtime);
}
