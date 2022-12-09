#include "../../includes/fdf.h"

// funtion that is called each frames
int	on_update(t_data *data)
{
	draw_background(&data->img, rgb(45, 69, 113));

	draw_rect(&data->img, (t_rect){100, 100, 100, 100});
	draw_line(200, 200, 400, 400, &data->img, rgb(170, 149, 57));

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
