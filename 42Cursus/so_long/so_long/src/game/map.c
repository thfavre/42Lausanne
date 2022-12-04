
#include "../../include/so_long.h"

void	parse_map(t_data *data, char *map_path);

bool	init_map(t_data *data, char *map_path)
{
	int			fd;
	char		*line;
	t_vector2	pos;
	int			i;
	int			x;
	enum		tile_type;
	int			line_len;

	fd = open(map_path, O_RDWR);
	line = " ";
	data->map.tiles_nb = 0;
	data->map.width = 0;
	data->map.height = -1;
	data->map.obst_nb = 0;
	data->map.player_nb = 0;
	while (line)
	{
		data->map.height++;
		data->map.tiles_nb += ft_strlen(line) - 1;  // -1 for the /n
		i = 0;
		line = get_next_line(fd);
		if (data->map.width == 0)
		{
			data->map.width = ft_strlen(line) - 1;
		}
		while (line && line[i] != '\n')
		{
			if (line[i] == TILE_WALL)
				data->map.obst_nb++;
			else if (line[i] == TILE_PLAYER)
				data->map.player_nb++;
			i++;
		}
	}
	printf("tiles nbr : %d, %d, %d\n", data->map.tiles_nb, data->map.width, data->map.height);
	close(fd);

	// data->map.tiles = malloc(sizeof(*data->map.tiles) * data->map.tiles_nb);
	// fd = open(map_path, O_RDWR);
	// line = "";
	// pos = (t_vector2){0, 0};
	// i = 0;
	// while (line)
	// {
	// 	x = 0;
	// 	line = get_next_line(fd);
	// 	while (x < data->map.width)
	// 		printf("%c\n", line[x++]);
	// 	//tile_type =
	// 	//data->map.tiles[i] {line[i]}
	// 	i++;
	// }
	parse_map(data, map_path);
	printf("<MAP PARSED\n");
	return (true);
}

void	parse_map(t_data *data, char *map_path)
{
	int			fd;
	t_vector2	pos;
	int			i;
	char		*line;

	fd = open(map_path, O_RDWR);
	pos.y = 0;
	i = 0;
	data->map.tiles = malloc(sizeof(*data->map.tiles) * data->map.tiles_nb + 1000); // TODO there is an error somwhere
	data->map.obstacles = malloc(sizeof(*data->map.obstacles) * data->map.obst_nb + 1000);
	data->map.players = malloc(sizeof(*data->map.players) * data->map.player_nb + 1000);
	printf("++>%d\n", data->map.obst_nb);
	int obs_count = 0;
	int players_count = 0;
	while (pos.y < data->map.height)
	{
		pos.x = 0;
		line = get_next_line(fd);
		while (pos.x < data->map.width)
		{
			data->map.tiles[i] = (t_tile){line[pos.x], (t_vector2){pos.x, pos.y}};
			if (line[pos.x] == TILE_WALL)
				data->map.obstacles[obs_count++] = create_obstacle((t_rect){pos.x * TILE_SIZE, pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE});
			 else if (line[pos.x] == TILE_PLAYER)
			 	data->map.players[players_count++] = create_player((t_rect){pos.x * TILE_SIZE, pos.y * TILE_SIZE, TILE_SIZE, TILE_SIZE}, data->mlx_ptr);
			pos.x++;
		}
		pos.y++;
	}
}


void	create_map(t_data *data, char *path)
{


}
