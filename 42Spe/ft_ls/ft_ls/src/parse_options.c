#include "ft_ls.h"


void	fill_options(t_options *options, char *options_str) {
	if (options_str[0] != '-') {
		ft_lstadd_back(&options->paths, ft_lstnew(options_str));
		return ;
	}
	options_str++;
	while (*options_str) {
		if (*options_str == 'a') {
			options->a = true;
			options->A = false;
		}
		else if (*options_str == 'A'){
			options->a = false;
			options->A = true;
		}
		else if (*options_str == 'l')
			options->l = true;
		else if (*options_str == 'r')
			options->r = true;
		else if (*options_str == 'R')
			options->R = true;
		else if (*options_str == 't')
			options->t = true;
		else if (*options_str == 'U')
			options->U = true;
		else if (*options_str == 'f'){
			options->U = true;
			options->a = true;
		}
		else {
			ft_putstr_fd("ls: invalid option -- '", 2);
			ft_putchar_fd(*options_str, 2);
			ft_putstr_fd("'\n", 2);
			exit(2);
		}
		options_str++;
	}
}

t_options	parse_options(int ac, char **av) {
	t_options	options = {0};

	ac--;
	av++;

	while (ac-- > 0) {
		fill_options(&options, *av);
		av++;
	}
	if (!options.paths)
		options.paths = ft_lstnew(".");
	return (options);
}

