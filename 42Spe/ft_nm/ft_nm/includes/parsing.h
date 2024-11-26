#ifndef PARSING_H
# define PARSING_H

typedef struct	s_options {
	bool	a;  // Print all symbols
	bool	g;  // Print only global (external) symbols
	bool	u;  // Print only undefined symbols
	bool	r;  // Sort symbols in reverse order
	bool	p;  // Do not sort symbols; use their natural order
} t_options;

void	parse_args(char **args, t_options *options, t_list **files);

#endif
