/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:03:08 by thfavre           #+#    #+#             */
/*   Updated: 2023/03/20 15:16:29 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_keypressed(bool keypressed[400])
{
	int	i;

	i = 0;
	while (i < 400)
		keypressed[i++] = false;
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode < 400)
		data->keypressed[keycode] = true;
	if (keycode == K_ESC)
		close_mlx(data);
	return (0);
}

int	on_keyrelease(int keycode, t_data *data)
{
	if (keycode < 400)
		data->keypressed[keycode] = false;
	return (0);
}

int	close_mlx(t_data *data)
{
	int	i;

	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	i = 0;
	while (i < data->map.size.y)
		free(data->map.cells[i++]);
	free(data->map.cells);
	exit(1);
	return (1);
}
