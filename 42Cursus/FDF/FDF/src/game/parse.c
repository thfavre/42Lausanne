/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:07:16 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/17 19:07:16 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_vector2	get_map_size(char *map_path);

void	parse(char *map_path, t_map *map)
{
	int			fd;
	char		*line;
	char		**splited_line;
	t_vector2	pos;

	pos.y = -1;
	fd = open(map_path, O_RDWR);
	map->size = get_map_size(map_path);
	map->cells = malloc(sizeof(*map->cells) * map->size.y);
	while (++pos.y < map->size.y)
	{
		line = get_next_line(fd);
		splited_line = ft_split(line, ' ');
		free(line);
		map->cells[pos.y] = malloc(sizeof(**map->cells) * map->size.x);
		pos.x = -1;
		while (++pos.x < map->size.x)
		{
			map->cells[pos.y][pos.x].vect3.x = pos.x;
			map->cells[pos.y][pos.x].vect3.y = pos.y;
			map->cells[pos.y][pos.x].vect3.z = ft_atoi(splited_line[pos.x]);
			free(splited_line[pos.x]);
		}
		free(splited_line);
	}
}

t_vector2	get_map_size(char *map_path)
{
	t_vector2	size;
	int			i;
	char		*line;
	int			fd;

	size = (t_vector2){0, 0};
	fd = open(map_path, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (line && line[i])
	{
		if ((i == 0 || line[i - 1] == ' ') && line[i] != ' ')
			size.x++;
		i++;
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size.y++;
	}
	close(fd);
	return (size);
}
