/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:20:44 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/19 10:27:54 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	make_effects(t_data *data)
{
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
	if (data->keypressed[K_SPACE])
		data->attributes.moving_colors = true;
	if (data->attributes.moving_colors)
		data->attributes.color_disco++;
	if (data->attributes.moving_wave)
		data->attributes.wave_pos += 0.05 * WAVE_SPEED;
}

// funtion that is called each frames
int	on_update(t_data *data)
{
	draw_background(&data->img, rgb(11, 22, 22));
	make_effects(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->img.mlx_img, 0, 0);
	return (0);
}
