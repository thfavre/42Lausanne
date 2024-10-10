#include "ft_ls.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>




int handle_file(const char *path, struct stat *entity_stat, long *total_blocks) {
    if (lstat(path, entity_stat) == -1) {
        perror("lstat");
        return -1;
    }

    // ft_printf(" (%d, %d) ", entity_stat->st_blocks, entity_stat->st_size);
    *total_blocks += entity_stat->st_blocks;
    return 0;
}
