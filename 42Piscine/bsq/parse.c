/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:18:04 by jchapell          #+#    #+#             */
/*   Updated: 2022/09/21 23:26:51 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "prototype.h"

char	**create_map(char *unparsed, int i, int size);
int		file_char_len(char *file_path);

char	*parse(char *file_path)
{
	int		file;
	int		i;
	char	*parsed;
	char	buffer;

	parsed = malloc(sizeof(char) * file_char_len(file_path));
	file = open(file_path, O_RDONLY);
	i = 0;
	if (file == -1)
		return (0);
	while (read(file, &buffer, sizeof(char)) != 0)
	{
		parsed[i] = buffer;
		i++;
	}
	close(file);
	return (parsed);
}

int	file_char_len(char *file_path)
{
	int		file;
	int		i;
	char	buffer;

	file = open(file_path, O_RDONLY);
	i = 0;
	if (file == -1)
		return (0);
	while (read(file, &buffer, sizeof(char)) != 0)
		i++;
	close(file);
	return (i);
}

t_level	set_level_data(char *nb, int i, char *unparsed)
{
	t_level	result;

	result.data.size = ft_atoi(nb);
	result.data.empty = unparsed[i - 3];
	result.data.obstacle = unparsed[i - 2];
	result.data.square = unparsed[i - 1];
	result.map = create_map(unparsed, (i + 1), result.data.size);
	free(nb);
	return (result);
}

t_level	parse_level(char *unparsed)
{
	int		i;
	int		j;
	char	*nb;
	t_level	result;

	i = 0;
	j = 0;
	while (unparsed[i] != '\n')
		i++;
	nb = malloc(sizeof(char) * (i - 3));
	if (i < 4)
	{
		result.data.size = -1;
		return (result);
	}
	while (j != i - 3)
	{
		nb[j] = unparsed[j];
		j++;
	}
	result = set_level_data(nb, i, unparsed);
	return (result);
}

char	**create_map(char *unparsed, int i, int size)
{
	int		line;
	int		x;
	char	**result;

	line = 0;
	x = 0;
	result = malloc(sizeof(char *) * (size + 1));
	result[0] = malloc(sizeof(char) * (size + 0));
	while (unparsed[i])
	{
		if (unparsed[i] == '\n')
		{	
			line++;
			result[line] = malloc(sizeof(char) * size);
			x = 0;
		}
		else
		{
			result[line][x] = unparsed[i];
			x++;
		}
		i++;
	}
	return (result);
}
