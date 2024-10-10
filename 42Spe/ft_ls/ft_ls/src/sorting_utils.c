// sorting_utils.c
#include "ft_ls.h"

int lst_compare_fn_dirent_str(const void *dirent1, const void *dirent2) {
    const struct dirent *d1 = (const struct dirent *)dirent1;
    const struct dirent *d2 = (const struct dirent *)dirent2;
    return (ft_strcmp(d1->d_name, d2->d_name));
}
