#include "so_long.h"

#ifndef DATA_H
# define DATA_H

typedef struct	s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_rect;

typedef struct	s_obstacle
{
	t_rect		rect;
	void		(*draw)(struct s_obstacle *self, t_img *img);
}				t_obstacle;

typedef struct	s_player
{
	t_fvector2	pos;
	t_rect		rect;
	float		move_speed;
	t_fvector2	velocity;
	bool		on_ground;
	void		(*move)(struct s_player *self, t_obstacle obstacle, bool *keypressed);
	void		(*draw)(struct s_player *self, t_img *img);
}				t_player;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_rect		*r1;
	bool		keypressed[200];
	t_player	player;
	t_obstacle	obstacle;
}				t_data;


#endif
