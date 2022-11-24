/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:15 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/24 14:51:01 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> // TODO delete ethis
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>

# include "../mlx/mlx.h"
# include "../src/Libft/libft.h"
# include "vector2.h"
# include "data.h"
# include "keycodes.h"
# include "events.h"

// default settings
//	window
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
//	player
# define PLAYER_VELOCITY 5

int		rgb(uint8_t red, uint8_t green, uint8_t blue);
int		argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);


int	on_update(t_data *data);

void	init_keypressed(bool keypressed[200]);
int		on_keypress(int keycode, t_data *data);
int		on_keyrelease(int keycode, t_data *data);

t_player create_player();
/*
mlx_hook :
	X11 events
		Usage : mlx_hook(vars.win, EVENT_XXX, MASK, event_function, &vars);
		Event functions have a different prototype depending of the hooking event.

	Event functions have a different prototype depending of the hooking event.
		EVENT_KEYDOWN :  int (*f)(int keycode, void *param)
		EVENT_KEYUP : int (*f)(int keycode, void *param)
		EVENT_MOUSEDOWN : int (*f)(int button, int x, int y, void *param)
		EVENT_MOUSEUP : int (*f)(int button, int x, int y, void *param)
		EVENT_MOUSEMOVE : int (*f)(int x, int y, void *param)
		EVENT_EXPOSE : int (*f)(void *param)
		EVENT_DESTROY : int (*f)(void *param)

	Alias :
		mlx_expose_hook function is an alias of mlx_hook on expose event (12)
		mlx_key_hook function is an alias of mlx_hook on key up event (3)
		mlx_mouse_hook function is an alias of mlx_hook on mouse down event (4)

	X11 masks
		Each X11 event, also has a according mask.
		This way you can register to only one key when it triggers,
		or to all keys if you leave your mask to the default.
		Key masks therefore allow you to whitelist
		/ blacklist events from your event subscriptions.
			0L : NoEventMask
			(1L<<0) : KeyPressMask
			...
*/

#endif
