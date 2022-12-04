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
	t_vector2	size;
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

typedef struct s_player
{
	t_fvector2	pos;
	t_rect		rect;
	t_img		img;
	t_fvector2	vel;  //velocity
	enum e_grav	gravity_dir;
	float		gravity;
	float		max_gravity;
	void		(*move)(struct s_player *self, t_obstacle *obstacles, \
					int obst_nb, bool *keypressed);
	void		(*draw)(struct s_player *self, t_img *img);
}				t_player;

typedef struct s_collectible
{
	bool		is_collected;
	t_rect		rect;
	void		(*draw)(struct s_collectible *self, t_img *img);
}				t_collectible;

enum e_tile
{
	TILE_ITEM = 'C',
	TILE_WALL = '1',
	TILE_EXIT = 'E',
	TILE_PLAYER = 'P',
	TILE_EMPTY = '0'
};

typedef struct s_tile
{
	enum e_tile	type;
	t_vector2	pos;
}				t_tile;



typedef struct s_map
{
	int			width;
	int			height;
	int			tiles_nb;
	t_tile		*tiles;
	int			player_nb;
	t_player	*players;
	int			obst_nb;
	t_obstacle	*obstacles;
	int			collectibles_nb;
}				t_map;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	bool			keypressed[400];
	t_map			map;
	int				moves; // count the moves nbr
	bool 			has_win;
}					t_data;

#endif
