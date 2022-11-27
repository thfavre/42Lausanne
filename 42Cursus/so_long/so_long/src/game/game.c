
#include "../../include/so_long.h"

// funtion that is called each frames
int	on_update(t_data *data)
{
	static int direction = 1;

	data->r1->x += 20 * direction;
	if (data->r1->x <= 0)
	{
		data->r1->x = 0;
		direction = 1;
	}
	if (data->r1->x + data->r1->width >= WINDOW_WIDTH)
	{
		data->r1->x = WINDOW_WIDTH - data->r1->width;
		direction = -1;
	}


	//render_background(data, rgb(0, 0, 100));
	draw_background(&data->img, rgb(222, 222, 222));
	//render_rect(&data->img, *(data->r1));
	//render_rect(&data->img, (t_rect){777, 77, 100, 100, rgb(111, 111, 100)});
	// player
	data->player.draw(&data->player, &data->img);

	data->obstacles[0].draw(&(data->obstacles[0]), &data->img);
	data->obstacles[1].draw(&data->obstacles[1], &data->img);
	data->player.move(&data->player, data->obstacles, data->keypressed);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
