#include "../includes/fdf.h"

bool	init_data(t_data *data, char *map_path)
{
	init_keypressed(data->keypressed);
	data->map = parse(map_path);
	//t_vector3	offset = {0, 0}; //{40 * 10, 50 * 5, 0};
	//move_cells(data->map, offset);
	data->attributes.zoom_factor = DEFAULT_ZOOM_FACTOR;
	data->attributes.line_width = 1;
	data->attributes.offset = (t_vector2){0, 0};
	//data->need_redraw = true;
	return (true);
}

int main()
{
	t_data	data;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,"FDF    move : wasd");

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
						&data.img.line_len, &data.img.endian);

	init_data(&data, "maps/test_maps/42_1.fdf");

	// /* Setup hooks */
	mlx_hook(data.win_ptr, EVENT_KEYDOWN, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, EVENT_KEYUP, 0, &on_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &on_update, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
}
