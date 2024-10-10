// directory_utils.c
#include "ft_ls.h"
#include <stdio.h>
#include <errno.h>

DIR *open_directory(const char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        handle_open_error(dirname);
    }
    return dir;
}

void handle_open_error(const char *dirname) {
    if (errno == EACCES) {
        fprintf(stderr, "ls: cannot open directory '%s': Permission denied\n", dirname);
    } else {
        fprintf(stderr, "ls: cannot access '%s': No such file or directory\n", dirname);
    }
}

void handle_directory(const char *path, t_list **directories) {
    ft_lstadd_back(directories, ft_lstnew(ft_strdup(path)));
}
