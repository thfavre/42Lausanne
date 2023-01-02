#include "../../includes/fdf.h"

// funtion that is called each frames
int	on_update(t_data *data)
{
	draw_background(&data->img, rgb(11, 22, 22));

	move(data);
	zoom(data);
	rotate(data);
	if (data->keypressed[K_Q])
		data->attributes.line_width--;
	if (data->attributes.line_width < 1)
		data->attributes.line_width = 1;
	if (data->keypressed[K_E])
		data->attributes.line_width++;
	if (data->keypressed[K_C])
			data->attributes.perspective_type = conical;
	if (data->keypressed[K_I])
			data->attributes.perspective_type = isometric;

	//printf("%d\n", data->attributes.line_width);

	if (data->attributes.perspective_type == isometric)
		draw_isometric(data);
	else if (data->attributes.perspective_type == conical)
		draw_conical(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
