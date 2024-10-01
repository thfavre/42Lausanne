#include <dirent.h>
#include "libft.h"
#include <string.h>
#include <errno.h>
#include "ft_ls.h"

int	lst_compare_fn_dirent_str(const void *dirent1, const void *dirent2) {
	const struct dirent *d1 = (const struct dirent *)dirent1;
    const struct dirent *d2 = (const struct dirent *)dirent2;
    return (ft_strcmp(d1->d_name, d2->d_name));
    // return (ft_strcmp(dirent1, dirent2));
}


void sort_list(t_list *lst, t_options *options) {
	ft_lstsort(lst, lst_compare_fn_dirent_str);
}

#define BOLD_BLUE "\033[1;34m"
#define BOLD_CYAN "\033[1;36m"
#define COLOR_RESET "\033[0m"

void	print_all_dirents(t_list *all_dirents, t_options *options) {

	sort_list(all_dirents, options);
	// ! TODO free t_list
	while (all_dirents && all_dirents->content) {
		const struct dirent *entity = (const struct dirent *)all_dirents->content;
		if (entity->d_type == DT_DIR) // directories
            ft_printf(BOLD_BLUE); // Bold Blue for directories
        else if (entity->d_type == DT_LNK)
            ft_printf(BOLD_CYAN); // symbolic links
        else
            ft_printf(COLOR_RESET); // Default color for other types

        ft_printf("%s\t", entity->d_name);
        ft_printf(COLOR_RESET); // Reset color
		all_dirents = all_dirents->next;
	}
}

t_list *list_files(const char *dirname, t_options *options) {
	struct dirent	*entity;
	DIR 			*dir;

	dir = opendir(dirname);
	if (dir == NULL) {
		if (errno == EACCES) {
			// TODO write on stderr
			ft_printf("\n\nls: cannot open directory '%s': Permission denied\n\n", dirname);
			return NULL;
			exit(11);
		} else {

			// TODO on error
			ft_printf("\n\nls: cannot access '%s': No such file or directory\n\n", dirname);
			return NULL;
			exit(12);
		}
	}

	t_list	*directories = NULL;
	t_list	*all_dirents = NULL; // ? TODO rename to entity_names
	while ((entity = readdir(dir)) != NULL) {
		// if (entity == NULL) continue;  // Added safety check

		// if not the -a option
		if (entity->d_name[0] == '.') continue;

		// ft_printf("%s\t", entity->d_name);
		ft_lstadd_back(&all_dirents, ft_lstnew(entity)); // ? TODO no need of strdup
		if (entity->d_type == DT_DIR && ft_strcmp(entity->d_name, ".") != 0 && ft_strcmp(entity->d_name, "..") != 0) {
			char path[1000] = { 0 }; // TODO find better way
			ft_strlcat(path, dirname, 1000);
			ft_strlcat(path, "/", 1000);
			ft_strlcat(path, entity->d_name, 1000);
			ft_lstadd_back(&directories, ft_lstnew(ft_strdup(path)));
		}

	}
	// print all files
	print_all_dirents(all_dirents, options);

	closedir(dir);
	return (directories);

}


void	list_files_recursively(const char *dirname, t_list *queue, t_options *options) {
	if (queue) {
		queue = queue->next;
	}
	// IF OPTION -R
	ft_printf("\n---\n%s:\n", dirname);
	t_list *directories = list_files(dirname, options);
	sort_list(directories, options);

	if (!queue)
		queue = directories;
	else {
		t_list *tmp = queue;
		queue = directories;
		ft_lstadd_back(&queue, tmp);
	}
	if (queue)
		list_files_recursively(queue->content, queue, options);
}
