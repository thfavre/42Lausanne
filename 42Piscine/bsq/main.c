/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:29:04 by jchapell          #+#    #+#             */
/*   Updated: 2022/09/21 23:29:23 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototype.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	work(char **argv, int i)
{
	t_level	level;
	char	*str_level;

	str_level = parse(argv[i]);
	if (str_level == 0)
	{
		print_errors(1, str_level);
		return ;
	}
	level = parse_level(str_level);
	if (level.data.size == -1)
	{
		print_errors(1, str_level);
		return ;
	}
	if (parse_validity(str_level, level.data) == 0)
	{
		print_errors(1, str_level);
		return ;
	}
	draw_bigger_square(level, 0);
	write(1, "\n", 1);
	free(str_level);
	free(level.map);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str_level;
	t_level	level;

	i = 1;
	if (argc == 1)
	{
		str_level = read_stdin();
		if (str_level == NULL)
			return (1);
		if (str_level == 0)
			return (print_errors(1, str_level));
		level = parse_level(str_level);
		if (level.data.size == -1)
			return (print_errors(1, str_level));
		if (parse_validity(str_level, level.data) == 0)
			return (print_errors(1, str_level));
		draw_bigger_square(level, 0);
		free(str_level);
		free(level.map);
		return (0);
	}
	while (i < argc)
		work(argv, i++);
	return (0);
}
