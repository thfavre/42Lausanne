#include "../so_long.h"

#ifndef DATA_H
# define DATA_H

typedef struct s_rect
{
    int x;
    int y;
    int width;
    int height;
    int color;
}   t_rect;


typedef struct s_data
{
    int     WINDOW_WIDTH;
    int     WINDOW_HEIGHT;
	void	*mlx_ptr;
	void	*win_ptr;
	t_rect  *r1;
}	t_data;


#endif