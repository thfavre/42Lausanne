#include "libft.h"
#include "parsing.h"

void	fill_options(t_options *options, t_list **files, char *options_str) {
	if (options_str[0] != '-') {
		ft_lstadd_back(files, ft_lstnew(options_str));
		return ;
	}
	options_str++;
	while (*options_str) {
		if (*options_str == 'a')
			options->a = true;
		else if (*options_str == 'g')
			options->g = false;
		else if (*options_str == 'u')
			options->u = true;
		else if (*options_str == 'r')
			options->r = true;
		else if (*options_str == 'p')
			options->p = true;
		else {
			ft_fprintf(STDERR_FILENO, "nm: invalid option -- '%s'", *options_str);
			exit(EXIT_FAILURE);
		}
		options_str++;
	}
}

void	parse_args(char **args, t_options *options, t_list **files) {
	// t_options	options = {0};

	while (*args) {
		fill_options(options, files, *args);
		args++;
	}
	if (!(*files))
		*files = ft_lstnew("a.out");
}

