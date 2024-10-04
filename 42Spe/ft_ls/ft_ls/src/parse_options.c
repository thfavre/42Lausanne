#include "ft_ls.h"

void	fill_option(t_options *options, char *options_str) { // ? TODO find better name for options_str
	// the option is a folder path
	if (options_str[0] != '-') {
		ft_lstadd_back(&options->paths, ft_lstnew(options_str));
		// ft_printf("'%s' added to paths\n", options_str);
		return ;
	}
	// the option is an option // TODO find better comment
	options_str++;
	while (*options_str) {
		if (*options_str == 'a')
			options->a = true;
		else if (*options_str == 'l')
			options->l = true;
		else if (*options_str == 'r')
			options->r = true;
		else if (*options_str == 'R')
			options->R = true;
		else if (*options_str == 't')
			options->t = true;
		else {
			ft_printf("ls: invalid option -- '%c'\n", *options_str);
			exit(2);
		}
		// printf("option '%c' is set to true\n", *options_str);
		options_str++;
	}
}

t_options	parse_options(int ac, char **av) {
	t_options	options = {0};

	ac--;
	av++;

	while (ac-- > 0) {
		fill_option(&options, *av);
		av++;
	}
	if (!options.paths)
		options.paths = ft_lstnew(".");
	return (options);
}

