#ifndef FT_LS_H
# define FT_LS_H

#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include "libft.h"

#define BOLD_BLUE "\033[1;34m"
#define BOLD_CYAN "\033[1;36m"
#define COLOR_RESET "\033[0m"


typedef struct	s_options {
	// char	**paths;
	// int		paths_len;
	t_list	*paths; // TODO ? put in other struc
	bool	a;	// do not ignore entries starting with .
	bool	A;	// do not list implied . and .
	bool	l;	// use a long listing format
	bool	r;	// reverse order while sorting
	bool	R;	// list subdirectories recursively
	bool	t;	// sort by time, newest first
	bool	U;	// does not sort
	// bool	f;	// does U + a
}				t_options;

typedef struct s_entity {
    struct dirent dir_entry; // Directory entry (from readdir)
    struct stat entity_stat;   // File metadata (from stat)
}				t_entity;

// directory.c
DIR			*open_directory(const char *dirname);
void		handle_directory(const char *path, t_list **directories);

// entity_handling.c
void		process_entity(const char *dirname, struct dirent *dir_entry, t_list **directories, t_list **entities, long *total_blocks, t_options *options);

// file.c
int			handle_file(const char *path, struct stat *entity_stat, long *total_blocks);

// listing.c
t_list		*list_entities(const char *dirname, t_options *options, bool is_recursive);
void		list_entities_recursively(const char *dirname, t_list *queue, t_options *options);

// parse_options.c
t_options	parse_options(int ac, char**av);

// path_handling.c
void		process_paths(t_options *options);

// print_entities_long.c
void    	print_entities_long_format(t_list *entities, t_options *options, long total_blocks);

// print_entities.c
void		print_entities(t_list *entities, t_options *options);
void		print_entity_name(const t_entity *entity);

// sorting_utils.c
int			lst_compare_fn_entity_str(const void *entity1, const void *entity2);
int			lst_compare_fn_entity_time(const void *entity1, const void *entity2);


#endif	// FT_LS_H
