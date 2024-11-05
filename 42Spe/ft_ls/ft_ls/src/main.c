#include "ft_ls.h"


int main(int ac, char **av) {
	t_options options = parse_options(ac, av);
	process_paths(&options);
	return 0;
}
