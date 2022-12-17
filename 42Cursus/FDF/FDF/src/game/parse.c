#include "../../includes/fdf.h"

t_vector2	get_map_size(char *map_path);

t_map	parse(char *map_path)
{
	int			fd;
	char		*line;
	char		**splited_line;
	t_vector2	curr_pos;
	t_map		map;

	curr_pos.y = 0;
	fd = open(map_path, O_RDWR);
	map.size = get_map_size(map_path);;

	map.cells = malloc(sizeof(*map.cells) * map.size.y);

	while (curr_pos.y < map.size.y)
	{
		line = get_next_line(fd);
		splited_line = ft_split(line, ' ');
		map.cells[curr_pos.y] = malloc(sizeof(**map.cells) * map.size.x);
		curr_pos.x = 0;
		while (curr_pos.x < map.size.x)
		{
			// TODO check if number
			map.cells[curr_pos.y][curr_pos.x].vect3.x = curr_pos.x;
			map.cells[curr_pos.y][curr_pos.x].vect3.y = curr_pos.y;
			map.cells[curr_pos.y][curr_pos.x].vect3.z = ft_atoi(splited_line[curr_pos.x]);
			curr_pos.x++;
		}
		curr_pos.y++;
	}
	close(fd);
	return (map);
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
	while (line[i])
	{
		if ((i == 0 || line[i - 1] == ' ') && line[i] != ' ')
			size.x++;
		i++;
	}
	while (line)
	{
		line = get_next_line(fd);
		size.y++;
	}
	close(fd);
	return (size);
}
