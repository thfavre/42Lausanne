#include "ft_ls.h"
#include <sys/stat.h>


int handle_file(const char *path, struct stat *entity_stat, long *total_blocks) {
	if (lstat(path, entity_stat) == -1) {
		perror("lstat");
		return -1;
	}
	*total_blocks += entity_stat->st_blocks;
	return 0;
}
