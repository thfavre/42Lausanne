
#include "../../includes/fdf.h"

t_vector3	apply_transformations(t_data *data, int x, int y)
{
	t_vector3 new_vect3;

	new_vect3 = mult_vector3_float(data->map.cells[y][x].vect3, data->attributes.zoom_factor);
	new_vect3 = mult_vector3_dvector3(new_vect3, (t_dvector3){1, 1, data->attributes.height_zoom});
	return (new_vect3);
}

void	rotate(t_data *data)
{
	if (data->keypressed[K_R] && !data->keypressed[K_SHIFT])
		data->attributes.angle += 0.005 * ROTATE_SPEED;
	else if (data->keypressed[K_R])
		data->attributes.angle -= 0.005 * ROTATE_SPEED;
}

void	zoom(t_data *data)
{
	if (data->keypressed[K_Z] && !data->keypressed[K_SHIFT])
		data->attributes.zoom_factor += 0.05 * ZOOM_SPEED;
	else if (data->keypressed[K_Z])
		data->attributes.zoom_factor -= 0.05 * ZOOM_SPEED;
	if (data->attributes.zoom_factor < 0)
		data->attributes.zoom_factor = 0;

	if (data->keypressed[K_H] && !data->keypressed[K_SHIFT])
		data->attributes.height_zoom += 0.01 * HEIGHT_ZOOM_SPEED;
	else if (data->keypressed[K_H])
		data->attributes.height_zoom -= 0.01 * HEIGHT_ZOOM_SPEED;

}

void	move(t_data *data)
{
	if (data->keypressed[K_W])
		data->attributes.offset.y -= MOVE_SPEED;
	if (data->keypressed[K_S])
		data->attributes.offset.y += MOVE_SPEED;
	if (data->keypressed[K_A])
		data->attributes.offset.x -= MOVE_SPEED;
	if (data->keypressed[K_D])
		data->attributes.offset.x += MOVE_SPEED;
}
