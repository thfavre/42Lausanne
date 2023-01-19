/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:41:23 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/19 09:51:56 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°);
// v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°);
t_vector2	convert_vector3_to_isometric(t_vector3 vect3, double angle)
{
	t_vector2	vect2;

	vect2.x = vect3.x * cos(angle) + vect3.y * cos(angle + 2) + \
		vect3.z * cos(angle - 2);
	vect2.y = vect3.x * sin(angle) + vect3.y * sin(angle + 2) + \
		vect3.z * sin(angle - 2);
	return (vect2);
}

// u = x*cos(angle) + y*cos(angle + (180 - angle)/2) +
//		z*cos(angle - (180 - angle)/2);

// v = x*sin(angle) + y*sin(angle + (180 - angle)/2) +
//		z*sin(angle - (180 - angle)/2);
t_vector2	convert_vector3_to_conical(t_vector3 vect3, double angle)
{
	t_vector2	vect2;

	vect2.x = vect3.x * cos(angle) + vect3.y * cos(angle + (M_PI - angle) / 2) \
	+ vect3.z * cos(angle - (M_PI - angle) / 2);
	vect2.y = vect3.x * sin(angle) + vect3.y * sin(angle + (M_PI - angle) / 2) \
	+ vect3.z * sin(angle - (M_PI - angle) / 2);
	return (vect2);
}

void	transform_and_draw_line(t_vector2 pos1, t_vector2 pos2, t_data *data)
{
	t_vector2	new_start_pos;
	t_vector2	new_end_pos;

	if (data->attributes.perspective_type == isometric)
		new_start_pos = convert_vector3_to_isometric(apply_transformations(\
			data, pos1.x, pos1.y), data->attributes.angle);
	if (data->attributes.perspective_type == isometric)
		new_end_pos = convert_vector3_to_isometric(apply_transformations(\
			data, pos2.x, pos2.y), data->attributes.angle);
	else
	{
		new_start_pos = convert_vector3_to_conical(apply_transformations(data, \
		pos1.x, pos1.y), data->attributes.angle);
		new_end_pos = convert_vector3_to_conical(apply_transformations(data, \
		pos2.x, pos2.y), data->attributes.angle);
	}
	add_vector2_ip(&new_start_pos, data->attributes.offset);
	add_vector2_ip(&new_end_pos, data->attributes.offset);
	draw_line(*data, new_start_pos, new_end_pos, rgb(\
		pos1.x * 2 - data->attributes.color_disco + \
		data->attributes.offset.x * !data->attributes.moving_colors / 2, \
		122 + pos1.x * 3 + data->attributes.color_disco,
			222 - pos1.x * 3 + data->attributes.color_disco / 5 - \
		data->attributes.offset.y * !data->attributes.moving_colors / 2));
}

void	draw(t_data *data)
{
	t_vector2	curr_pos;

	curr_pos.y = 0;
	while (curr_pos.y < data->map.size.y)
	{
		curr_pos.x = 0;
		while (curr_pos.x < data->map.size.x)
		{
			if (curr_pos.x < data->map.size.x - 1)
				transform_and_draw_line(curr_pos, \
				(t_vector2){curr_pos.x + 1, curr_pos.y}, data);
			if (curr_pos.y < data->map.size.y - 1)
				transform_and_draw_line(curr_pos, \
				(t_vector2){curr_pos.x, curr_pos.y + 1}, data);
			curr_pos.x++;
		}
		curr_pos.y++;
	}
}
