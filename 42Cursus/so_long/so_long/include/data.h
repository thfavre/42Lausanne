#include "so_long.h"

#ifndef DATA_H
# define DATA_H

typedef struct s_img
{
	void    *mlx_img;
	char    *addr;
	int     bpp;
	int     line_len;
	int     endian;
}   t_img;

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
}	t_rect;

//typedef t_player;

typedef struct s_player
{
	t_fvector2	pos;
	t_rect		rect;
	float		velocity;
	void (*move)(struct s_player *self, bool *keypressed);
	void (*draw)(struct s_player *self, t_img *img);
}	t_player;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_rect		*r1;
	bool		keypressed[200];
	t_player	player;
}	t_data;


#endif
