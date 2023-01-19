/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:21:31 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/19 10:19:19 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_vector3	wave(t_data *data, t_vector3 vect3, int x);

t_vector3	apply_transformations(t_data *data, int x, int y)
{
	t_vector3	new_vect3;

	new_vect3 = mult_vector3_float(data->map.cells[y][x].vect3, \
		data->attributes.zoom_factor);
	new_vect3 = mult_vector3_dvector3(new_vect3, \
		(t_dvector3){1, 1, data->attributes.height_zoom});
	new_vect3 = wave(data, new_vect3, x);
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

t_vector3	wave(t_data *data, t_vector3 vect3, int x)
{
	if (data->keypressed[K_M])
			data->attributes.moving_wave = true;
	if (data->keypressed[K_N])
			data->attributes.moving_wave = false;
	if (data->attributes.moving_wave == true)
	{
		if (data->attributes.wave_pos >= data->map.size.x)
			data->attributes.wave_pos = 0;
		vect3.z += ((int)data->attributes.wave_pos == x) * 20 * WAVE_MULT;
		vect3.z += ((int)data->attributes.wave_pos == x - 1) * 15 * WAVE_MULT;
		vect3.z += ((int)data->attributes.wave_pos == x + 1) * 15 * WAVE_MULT;
		vect3.z += ((int)data->attributes.wave_pos == x - 2) * 5 * WAVE_MULT;
		vect3.z += ((int)data->attributes.wave_pos == x + 2) * 5 * WAVE_MULT;
		vect3.z += ((int)data->attributes.wave_pos == x - 3) * 1 * WAVE_MULT;
		vect3.z += ((int)data->attributes.wave_pos == x + 3) * 1 * WAVE_MULT;
	}
	return (vect3);
}
