#include <stdbool.h>
#include "libft.h"

typedef struct	s_options {
	// char	**paths;
	// int		paths_len;
	t_list	*paths;
	bool	a;	// do not ignore entries starting with .
	// bool	A;	// do not list implied . and .
	bool	l;	// use a long listing format
	bool	r;	// reverse order while sorting
	bool	R;	// list subdirectories recursively
	bool	t;	// sort by time, newest first
}				t_options;

// pase_options
t_options	parse_options(int ac, char**av);

// list_files
t_list	*list_files(const char *dirname, t_options *options);
void	list_files_recursively(const char *dirname, t_list *queue, t_options *options);


// typedef int (*compare_fn)(const void *, const void *);
// t_list	*lst_bubble_sort(t_list *lst, compare_fn cmp);
