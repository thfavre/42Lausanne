/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:15 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/23 15:55:38 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "src/Libft/libft.h"
# include "src/data.h"

/* 
mlx_hook :
    X11 events
        Usage : mlx_hook(vars.win, EVENT_XXX, MASK, event_function, &vars);
        Event functions have a different prototype depending of the hooking event.
*/ 
enum {
	EVENT_KEYDOWN = 2,
	EVENT_KEYUP = 3,
	EVENT_MOUSEDOWN = 4,
	EVENT_MOUSEUP = 5,
	EVENT_MOUSEMOVE = 6,
	EVENT_EXPOSE = 12,
	EVENT_DESTROY = 17
} ;
/*
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
