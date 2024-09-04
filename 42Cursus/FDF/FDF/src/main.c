/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:19:15 by thfavre           #+#    #+#             */
/*   Updated: 2023/03/20 15:16:13 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

bool	init_data(t_data *data, char *map_path)
{
	init_keypressed(data->keypressed);
	parse(map_path, &data->map);
	data->attributes.zoom_factor = (float)DEFAULT_ZOOM_FACTOR;
	data->attributes.line_width = 1;
	data->attributes.offset = (t_vector2){0, 0};
	data->attributes.angle = 0.5;
	data->attributes.height_zoom = 1;
	data->attributes.perspective_type = isometric;
	data->attributes.color_disco = 0;
	data->attributes.moving_colors = false;
	data->attributes.moving_wave = false;
	data->attributes.wave_pos = 3;
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		test_fd;

	if (argc != 2)
	{
		write(1, "You must include the map path (ex: maps/42.fdf)\n", 49);
		return (1);
	}
	test_fd = open(argv[1], O_RDWR);
	if (test_fd == -1)
		return (1);
	close(test_fd);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "\
	Move : wasd | Zoom: zZ | Zoom height: hH | Line width: qe | Rotate: rR | \
	Isometric: i | Conical: c | Disco: Space | Wave: mn");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
						&data.img.line_len, &data.img.endian);
	init_data(&data, argv[1]);
	mlx_hook(data.win_ptr, EVENT_KEYDOWN, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, EVENT_KEYUP, 0, &on_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &on_update, &data);
	mlx_hook(data.win_ptr, EVENT_DESTROY, 0, &close_mlx, &data);
	mlx_loop(data.mlx_ptr);
}
