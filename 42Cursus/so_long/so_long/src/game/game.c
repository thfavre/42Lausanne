
#include "../../include/so_long.h"

// funtion that is called each frames
int	on_update(t_data *data)
{
	int	i;
	//render_background(data, rgb(0, 0, 100));
	draw_background(&data->img, rgb(222, 222, 222));
	//render_rect(&data->img, *(data->r1));
	//render_rect(&data->img, (t_rect){777, 77, 100, 100, rgb(111, 111, 100)});
	// player
	data->player.draw(&data->player, &data->img);
	i = 0;
	while (i < data->map.obst_nb)
	{
		data->map.obstacles[i].draw(&(data->map.obstacles[i]), &data->img);
		data->map.obstacles[i].draw(&data->map.obstacles[i], &data->img);
		i++;
	}
	data->player.move(&data->player, data->map.obstacles, data->map.obst_nb, data->keypressed);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
