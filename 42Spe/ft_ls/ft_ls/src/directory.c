#include "ft_ls.h"
#include <stdio.h>
#include <errno.h>

void handle_open_error(const char *dirname);

DIR *open_directory(const char *dirname) {
	DIR *dir = opendir(dirname);
	if (dir == NULL) {
		handle_open_error(dirname);
	}
	return dir;
}

void handle_open_error(const char *dirname) {
	if (errno == EACCES) {
		ft_putstr_fd("ls: cannot open directory '", 2);
		ft_putstr_fd((char *)dirname, 2);
		ft_putstr_fd("': Permission denied\n", 2);
	} else {
		ft_putstr_fd("ls: cannot access '", 2);
		ft_putstr_fd((char *)dirname, 2);
		ft_putstr_fd("': No such file or directory\n", 2);
	}
}

void handle_directory(const char *path, t_list **directories) {
	ft_lstadd_back(directories, ft_lstnew(ft_strdup(path)));
}
