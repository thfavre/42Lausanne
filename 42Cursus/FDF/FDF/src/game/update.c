#include "../../includes/fdf.h"

// funtion that is called each frames
int	on_update(t_data *data)
{
	draw_background(&data->img, rgb(11, 22, 22));

	// draw_rect(&data->img, (t_rect){100, 100, 100, 100});
	// draw_line(&data->img, (t_vector2){200, 200}, (t_vector2){500, 400}, 3, rgb(170, 149, 57));

	// actions
	move(data->keypressed, data->map);

	if (data->keypressed[K_Z] && !data->keypressed[K_SHIFT])
		data->attributes.zoom_factor += 0.01;
		//zoom(data->map, 1.1);
	else if (data->keypressed[K_Z])
		data->attributes.zoom_factor -= 0.01;
		//zoom(data->map, 0.9);

	if (data->keypressed[K_Q])
		data->attributes.line_width--;
	if (data->attributes.line_width < 1)
		data->attributes.line_width = 1;
	if (data->keypressed[K_E])
		data->attributes.line_width++;

	draw_isometric(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
