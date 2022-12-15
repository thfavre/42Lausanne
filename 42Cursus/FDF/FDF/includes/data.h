
#include "fdf.h"

#ifndef DATA_H
# define DATA_H

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_rect;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector2	size;
}				t_img;

typedef struct s_cell
{
	t_vector3	vect3;
	// struct s_cell	*up;
	// struct s_cell	*left;
	// struct s_cell	*down;
	// struct s_cell	*right;
}					t_cell;

typedef struct s_map
{
	t_vector2	size;
	t_cell		**cells;
}					t_map;

typedef struct s_attributes
{
	double		zoom_factor;
	int			line_width;
	double		angle;
	t_vector2	offset;
}				t_attributes;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	//bool			need_redraw;
	t_img			img;
	bool			keypressed[400];
	t_map			map;
	t_attributes	attributes;

}					t_data;

#endif
