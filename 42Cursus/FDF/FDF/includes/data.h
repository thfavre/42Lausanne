
#include "fdf.h"

#ifndef DATA_H
# define DATA_H

typedef struct	s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_rect;

typedef struct	s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector2	size;
}				t_img;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	bool			keypressed[400];

}					t_data;

#endif
