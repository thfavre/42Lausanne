/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:38:03 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/19 10:21:52 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "fdf.h"

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

struct s_cell
{
	t_vector3	vect3;
} ;

typedef struct s_map
{
	t_vector2		size;
	struct s_cell	**cells;
}					t_map;

enum e_perspective_type
{
	conical,
	isometric
};

typedef struct s_attributes
{
	enum e_perspective_type	perspective_type;
	double					zoom_factor;
	double					height_zoom;
	int						line_width;
	double					angle;
	int						color_disco;
	bool					moving_colors;
	bool					moving_wave;
	float					wave_pos;
	t_vector2				offset;
}	t_attributes;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	bool			keypressed[400];
	t_map			map;
	t_attributes	attributes;

}					t_data;

#endif
