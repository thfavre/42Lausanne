/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:15 by thfavre           #+#    #+#             */
/*   Updated: 2022/12/01 09:53:09 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> // TODO delete ethis
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
#include <fcntl.h>

# include "../mlx/mlx.h"
# include "../src/Libft/libft.h"
# include "../src/gnl/get_next_line.h"
# include "vector2.h"
# include "data.h"
# include "keycodes.h"
# include "events.h"

// ---------- Default Settings ---------- //
//	window
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 1080
//	All will be scaled acording this value
# define TILE_SIZE 80
//	player
# define PLAYER_SIZE TILE_SIZE

// ---------- Functions ---------- //
//	render.c
/* Convert a rgb (red green blue) value to a int */
int			rgb(uint8_t red, uint8_t green, uint8_t blue);
/* Convert a argb (alpha red green blue) value to a int */
int			argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue);
/* Draw a pixel to the image */
void		img_pix_put(t_img *img, int x, int y, int color);
/* Draw a rect on the image */
void		draw_rect(t_img *img, t_rect rect);
/* Fill the img with the color */
void		draw_background(t_img *img, int color);
/*  */

//	game.c
/* Make all the game works, this function is called at each frame */
int			on_update(t_data *data);

//	keys.c
/* Set all the key to false (it means that they are not pressed) */
void		init_keypressed(bool keypressed[200]);
/* Set the key that is pressed to true */
int			on_keypress(int keycode, t_data *data);
/* Set the key that is released to false */
int			on_keyrelease(int keycode, t_data *data);

//	player.c
/* Create a player with the rect data */
t_player	create_player(t_rect rect, void *mlx);

// sprite.c
t_img create_sprite(void *mlx, char *path);

//	obstacle.c
/* Create an obstacle with the rect data */
t_obstacle	create_obstacle(t_rect rect);

//	collision.c
/* Returns true if two rect are colliding */
bool		colliderect(t_rect rect1, t_rect rect2);

/* Handle the collision of the player, obstacles SHOULD be NULL terminated */
void		player_collision_y(t_player *self, t_obstacle *obstacles, int obst_nb);
void		player_collision_x(t_player *self, t_obstacle *obstacles, int obst_nb);

//	map.c
bool	init_map(t_data *data, char *map_path);


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
