#ifndef FT_LS_H
# define FT_LS_H

#include <stdbool.h>
#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>


#define BOLD_BLUE "\033[1;34m"
#define BOLD_CYAN "\033[1;36m"
#define COLOR_RESET "\033[0m"



typedef struct	s_options {
	// char	**paths;
	// int		paths_len;
	t_list	*paths; // TODO ? put in other struc
	bool	a;	// do not ignore entries starting with .
	// bool	A;	// do not list implied . and .
	bool	l;	// use a long listing format
	bool	r;	// reverse order while sorting
	bool	R;	// list subdirectories recursively
	bool	t;	// sort by time, newest first
}				t_options;


typedef struct s_entity_info {
    struct dirent dir_entry; // Directory entry (from readdir)
    struct stat entity_stat;   // File metadata (from stat)
}				t_entity_info;
// pase_options
t_options	parse_options(int ac, char**av);

// list_files
t_list	*list_entities(const char *dirname, t_options *options);
void	list_entities_recursively(const char *dirname, t_list *queue, t_options *options);


DIR *open_directory(const char *dirname);
void handle_open_error(const char *dirname);
void process_entity(const char *dirname, struct dirent *entity, t_list **directories, t_list **all_dirents, long *total_blocks, t_options *options);
void handle_directory(const char *path, t_list **directories);
int handle_file(const char *path, struct stat *entity_stat, long *total_blocks);
// void print_file_info(struct stat *entity_stat);
void print_all_dirents(t_list *all_dirents, t_options *options);
void    print_all_dirents_long_format(t_list *all_dirents, t_options *options, long total_blocks);
// t_list *list_files(const char *dirname, t_options *options);
// void list_files_recursively(const char *dirname, t_list *queue, t_options *options);

int lst_compare_fn_dirent_str(const void *dirent1, const void *dirent2);
void sort_list(t_list *lst, t_options *options);


// typedef int (*compare_fn)(const void *, const void *);
// t_list	*lst_bubble_sort(t_list *lst, compare_fn cmp);


#endif	// FT_LS_H
