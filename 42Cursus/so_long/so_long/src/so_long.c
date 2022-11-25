/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:45:00 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/25 17:36:40 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
//#include <X11/keysym.h>


void	init_data(t_data *data)
{
	init_keypressed(data->keypressed);

}

int	main(void)
{
	t_data	data;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,"SUPER GAME");

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

	data.r1 = &((t_rect) {100, 100, 200, 200, rgb(100, 44, 0)});

	data.player = create_player((t_rect){400, 400, TILE_SIZE, TILE_SIZE});
	data.obstacle = create_obstacle((t_rect){0, 800, TILE_SIZE*40, TILE_SIZE*2});
	//data.player.move((t_vector2){2, 2});

	init_data(&data);

	// /* Setup hooks */

	mlx_hook(data.win_ptr, EVENT_KEYDOWN, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, EVENT_KEYUP, 0, &on_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &on_update, &data);
	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
}




