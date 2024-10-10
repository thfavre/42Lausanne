#include <dirent.h>
#include "libft.h"
#include <string.h>
#include <errno.h>
#include "ft_ls.h"
#include <sys/stat.h>


// Main function that lists files
t_list *list_entities(const char *dirname, t_options *options) {
    DIR *dir = open_directory(dirname);
    if (dir == NULL) return NULL;

    struct dirent *entity;
    t_list *directories = NULL;
    t_list *all_dirents = NULL;
    long total_blocks = 0;

    while ((entity = readdir(dir)) != NULL) {
        process_entity(dirname, entity, &directories, &all_dirents, &total_blocks, options);
    }

    // Print all files and total block count
	if (options->l)
		print_all_dirents_long_format(all_dirents, options, total_blocks);
	else
    	print_all_dirents(all_dirents, options);

    closedir(dir);
    return directories;
}

void	list_entities_recursively(const char *dirname, t_list *queue, t_options *options) {
	if (queue) {
		queue = queue->next;
	}
	// IF OPTION -R
	ft_printf("%s:\n", dirname);
	t_list *directories = list_entities(dirname, options);
	// sort_list(directories, options);
	ft_lstsort(directories, ft_lstsort_cmpft_str, options->r);

	if (!queue)
		queue = directories;
	else {
		t_list *tmp = queue;
		queue = directories;
		ft_lstadd_back(&queue, tmp);
	}
	// ft_printf("\n");
	if (queue) {
		ft_printf("\n");
		list_entities_recursively(queue->content, queue, options);
	}
}


// int	lst_compare_fn_dirent_str(const void *dirent1, const void *dirent2) {
// 	const struct dirent *d1 = (const struct dirent *)dirent1;
//     const struct dirent *d2 = (const struct dirent *)dirent2;
// 	// printf("hrer %s, %s\n", d1->d_name, d2->d_name);
//     return (ft_strcmp(d1->d_name, d2->d_name));
//     // return (ft_strcmp(dirent1, dirent2));
// }


// // void sort_list(t_list *lst, t_options *options) {
// // 	ft_lstsort(lst, lst_compare_fn_dirent_str, options->r);
// // }



// // Processes each entity in the directory (file or sub-directory)
// void process_entity(const char *dirname, struct dirent *entity, t_list **directories, t_list **all_dirents, long *total_blocks, t_options *options) {
//     // Skip hidden files if -a option is not set
//     if (!options->a && entity->d_name[0] == '.') return;

//     // Build the full path for the entity
//     char path[1000] = { 0 };
//     ft_strlcat(path, dirname, 1000);
//     ft_strlcat(path, "/", 1000);
//     ft_strlcat(path, entity->d_name, 1000);

//     // Handle if it's a directory
//     if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
//         handle_directory(path, directories);
//     }

//     // Handle the file (or symbolic link)
//     struct stat entity_stat;
//     if (handle_file(path, &entity_stat, total_blocks) == 0) {
//         ft_lstadd_back(all_dirents, ft_lstnew(entity));
//     }
// }

// // Handles adding a directory to the list
// void handle_directory(const char *path, t_list **directories) {
//     ft_lstadd_back(directories, ft_lstnew(ft_strdup(path)));
// }

// // Handles getting file stats and updates total block count
// int handle_file(const char *path, struct stat *entity_stat, long *total_blocks) {
//     if (lstat(path, entity_stat) == -1) {
//         perror("lstat");
//         return -1;  // Error handling file
//     }

// 	ft_printf(" (%d, %d) ", entity_stat->st_blocks, entity_stat->st_size);
//     *total_blocks += entity_stat->st_blocks;
//     return 0;  // Success
// }

// // Handles errors when opening the directory
// void handle_open_error(const char *dirname) {
//     if (errno == EACCES) {
//         // Permission denied
//         fprintf(stderr, "ls: cannot open directory '%s': Permission denied\n", dirname); // TODO do not use fprintf
//     } else {
//         // Other errors (e.g., directory not found)
//         fprintf(stderr, "ls: cannot access '%s': No such file or directory\n", dirname);
//     }
// }


// // Opens the directory and handles errors
// DIR *open_directory(const char *dirname) {
//     DIR *dir = opendir(dirname);
//     if (dir == NULL) {
//         handle_open_error(dirname);
//     }
//     return dir;
// }

// void	print_all_dirents(t_list *all_dirents, t_options *options) {

// 	// sort_list(all_dirents, options);
// 	ft_lstsort(all_dirents, lst_compare_fn_dirent_str, options->r);
// 	// ! TODO free t_list
// 	while (all_dirents && all_dirents->content) {
// 		const struct dirent *entity = (const struct dirent *)all_dirents->content;
// 		if (entity->d_type == DT_DIR) // directories
//             ft_printf(BOLD_BLUE); // Bold Blue for directories
//         else if (entity->d_type == DT_LNK)
//             ft_printf(BOLD_CYAN); // symbolic links
//         else
//             ft_printf(COLOR_RESET); // Default color for other types

//         ft_printf("%s\t", entity->d_name);
//         ft_printf(COLOR_RESET); // Reset color
// 		all_dirents = all_dirents->next;
// 	}
// 	ft_printf("\n");
// }
