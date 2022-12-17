#include "../includes/fdf.h"

bool	init_data(t_data *data, char *map_path)
{
	init_keypressed(data->keypressed);
	data->map = parse(map_path);
	//t_vector3	offset = {0, 0}; //{40 * 10, 50 * 5, 0};
	//move_cells(data->map, offset);
	data->attributes.zoom_factor = (float)DEFAULT_ZOOM_FACTOR;
	data->attributes.line_width = 1;
	data->attributes.offset = (t_vector2){0, 0};
	data->attributes.angle = 0.5;
	data->attributes.height_zoom = 1;
	//data->need_redraw = true;
	return (true);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		{
			write(1, "You must include the map path (ex: maps/42.fdf)\n", 49);
			return (1);
		}

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,"Move : wasd | Zoom: zZ | Zoom height: hH | Line width: qe | Rotate: rR");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
						&data.img.line_len, &data.img.endian);
	init_data(&data, argv[1]);
	mlx_hook(data.win_ptr, EVENT_KEYDOWN, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, EVENT_KEYUP, 0, &on_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &on_update, &data);
	mlx_hook(data.win_ptr, EVENT_DESTROY, 0, &close_mlx, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
