/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:07:35 by thfavre           #+#    #+#             */
/*   Updated: 2023/01/17 21:10:10 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct s_v
{
	bool		steep;
	t_vector2	start_pos;
	t_vector2	end_pos;
	t_vector2	xy;
	t_vector2	d;
	t_vector2	error;
}	t_v;

void	draw_line_1px(t_img img, t_v v, int color)
{
	if (v.start_pos.x > v.end_pos.x)
		swap(&v.start_pos.y, &v.end_pos.y);
	if (v.start_pos.x > v.end_pos.x)
		swap(&v.start_pos.x, &v.end_pos.x);
	v.d = (t_vector2){v.end_pos.x - v.start_pos.x, v.end_pos.y - v.start_pos.y};
	v.error = (t_vector2){abs(v.d.y) * 2, 0};
	v.xy = (t_vector2){v.start_pos.x - 1, v.start_pos.y - 1};
	while (++v.xy.x <= v.end_pos.x)
	{
		if (v.steep)
			img_pix_put(&img, v.xy.y, v.xy.x, color);
		else
			img_pix_put(&img, v.xy.x, v.xy.y, color);
		v.error.y += v.error.x;
		if (v.error.y > v.d.x)
		{
			if (v.end_pos.y > v.start_pos.y)
				v.xy.y += 1;
			else
				v.xy.y -= 1;
			v.error.y -= v.d.x * 2;
		}
	}
}

void	draw_line(t_data data, t_vector2 start_pos, t_vector2 end_pos, int col)
{
	int	i;
	t_v	v;

	i = -data.attributes.line_width / 2;
	while (i <= data.attributes.line_width / 2)
	{
		v.start_pos = (t_vector2){start_pos.x + i, start_pos.y};
		v.end_pos = (t_vector2){end_pos.x + i, end_pos.y};
		v.steep = abs(v.start_pos.x - v.end_pos.x) < \
			abs(v.start_pos.y - v.end_pos.y);
		if (v.steep)
			swap(&v.start_pos.x, &v.start_pos.y);
		if (v.steep)
			swap(&v.end_pos.x, &v.end_pos.y);
		draw_line_1px(data.img, v, col);
		i++;
	}
}
