/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:45:00 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/23 16:25:25 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//#include <X11/keysym.h>


int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	render_background(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return ;
	i = 0;
	while (i < data->WINDOW_HEIGHT)
	{
		j = 0;
		while (j < data->WINDOW_WIDTH)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
		++i;
	}
}

int render_rect(t_data *data, t_rect rect)
{
	int i;
	int	j;

	if (data->win_ptr == NULL)
		return (1);
	i = 0;
	j = 0;
	while (i < rect.width)
	{
		j = 0;
		while (j < rect.height)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, rect.x + i, rect.y + j, rect.color);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	static int direction = 1;

	data->r1->x += 20 * direction;
	if (data->r1->x <= 0)
	{
		data->r1->x = 0;
		direction = 1;
	}
	if (data->r1->x + data->r1->width >= data->WINDOW_WIDTH)
	{
		data->r1->x = data->WINDOW_WIDTH - data->r1->width;
		direction = -1;
	}
	//render_background(data, encode_rgb(0, 0, 100));
	render_rect(data, *(data->r1));
	render_rect(data, (t_rect){777, 77, 100, 100, encode_rgb(111, 111, 100)});
	return (0);
}


int	handle_keypress(int keycode, t_data *data)
{
	printf("PR : %d\n", keycode);
	//write(1, "adasd", 1);
	//putnbr_fd(keysym, 1);
	if (keycode == 53)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
	int speed = 20;
	if (keycode == 13) // W	
		data->r1->x -= speed;
	if (keycode == 0) // A
		data->r1->y -= speed;
	if (keycode == 1) // S
		data->r1->y += speed;
	if (keycode == 2) // D
		data->r1->x += speed;

	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	//printf("Re : %d\n", keycode);
	//write(1, "adasd", 1);
	//putnbr_fd(keysym, 1);
	// if (keycode == 0)
	// {
	// 	data->r1.x = 800; 
	// 	data->r1.y = 800;
	// }
	return (0);
}

int	main(void)
{
	t_data	data;

	data.WINDOW_WIDTH = 1920;
	data.WINDOW_HEIGHT = 1080;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.WINDOW_WIDTH, data.WINDOW_HEIGHT,"SUPER GAME");
	data.r1 = &((t_rect) {100, 100, 200, 200, encode_rgb(100, 44, 0)}); 

	// /* Setup hooks */
	 mlx_loop_hook(data.mlx_ptr, &render, &data);
	 mlx_hook(data.win_ptr, EVENT_KEYDOWN, 0, &handle_keypress, &data);
	 mlx_hook(data.win_ptr, EVENT_KEYUP, 0, &handle_keyrelease, &data);

	mlx_loop(data.mlx_ptr);
	
	/* we will exit the loop if there's no window left, and execute this code */
	free(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
}




