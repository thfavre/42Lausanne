/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:45:00 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/29 13:24:01 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//#include <X11/keysym.h>


bool	init_data(t_data *data, char *map_path)
{
	//data->map.obstacles = malloc(sizeof(*data->map.obstacles) * data->map.obst_nb);
	if (!init_map(data, map_path))
		return (false);
	init_keypressed(data->keypressed);
	data->has_win = false;


	return (true);
}

int	main(void)
{
	t_data	data;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,"Gravity controller");

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
						&data.img.line_len, &data.img.endian);

	char *map_path = "maps/map1.ber";
	init_data(&data, map_path);

	//data.player = create_player((t_rect){400, 400, TILE_SIZE, TILE_SIZE});
	//data.map.obstacles = malloc(sizeof(*data.map.obstacles) * data.map.obst_nb);
	// data.map.obstacles[0] = create_obstacle((t_rect){0, 800, TILE_SIZE*40, TILE_SIZE*2});
	// data.map.obstacles[1] = create_obstacle((t_rect){200, 100, TILE_SIZE*1, TILE_SIZE*18});
	// data.map.obstacles[2] = create_obstacle((t_rect){1000, 100, TILE_SIZE*1, TILE_SIZE*18});
	// data.map.obstacles[3] = create_obstacle((t_rect){0, 100, TILE_SIZE*40, TILE_SIZE*2});
	// data.map.obstacles[4] = create_obstacle((t_rect){440, 500, TILE_SIZE*7, TILE_SIZE*6});
	//data.player.move((t_vector2){2, 2});

	//init_data(&data);

	// /* Setup hooks */
	mlx_hook(data.win_ptr, EVENT_KEYDOWN, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, EVENT_KEYUP, 0, &on_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &on_update, &data);
	mlx_loop(data.mlx_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
}




