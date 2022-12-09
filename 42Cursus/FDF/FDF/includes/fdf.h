#ifndef FDF_H
# define FDF_H

# include <stdio.h>
#include <stdbool.h>

# include "../mlx/mlx.h"
# include "../src/Libft/libft.h"
# include "../src/gnl/get_next_line.h"

# include "vector.h"
# include "keycodes.h"
# include "events.h"
# include "data.h"


// ---------- Default Settings ---------- //
//	window
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 1080

// ---------- Functions ---------- //
//	keys.c
/* Set all the key to false (it means that they are not pressed) */
void		init_keypressed(bool keypressed[200]);
/* Set the key that is pressed to true */
int			on_keypress(int keycode, t_data *data);
/* Set the key that is released to false */
int			on_keyrelease(int keycode, t_data *data);

//	update
int			on_update(t_data *data);

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

void draw_line(int x0, int y0, int x1, int y1, t_img *img, int color);

#endif
