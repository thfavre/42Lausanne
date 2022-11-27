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

// gravity direction
enum	e_grav
{
	GRAV_UP,
	GRAV_LEFT,
	GRAV_DOWN,
	GRAV_RIGHT,
	GRAV_DISABLE
};

typedef struct	s_player
{
	t_fvector2	pos;
	t_rect		rect;
	t_fvector2	vel;  //velocity
	enum e_grav	gravity_dir;
	float		gravity;
	float		max_gravity;
	void		(*move)(struct s_player *self, t_obstacle *obstacles, bool *keypressed);
	void		(*draw)(struct s_player *self, t_img *img);
}				t_player;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_rect			*r1;
	bool			keypressed[400];
	t_player		player;
	t_obstacle		*obstacles;
	int				obstacles_
}					t_data;


#endif
