
#include "../../includes/fdf.h"

int	rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
{
	return (alpha << 24 |red << 16 | green << 8 | blue);
}

// like mlx_pixel_put but faster
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void draw_rect(t_img *img, t_rect rect)
{
	int i;
	int	j;

	i = 0;
	while (i < rect.width)
	{
		j = 0;
		while (j < rect.height)
		{
			img_pix_put(img, rect.x + i, rect.y + j, rect.color);
			j++;
		}
		i++;
	}
}

void	draw_background(t_img *img, int color)
{
	draw_rect(img, (t_rect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, color});
}

void draw_line(t_img *img, t_vector2 start_pos, t_vector2 end_pos, int line_width, int color)
{
	bool steep = false;
	if (abs(start_pos.x-end_pos.x)<abs(start_pos.y-end_pos.y)) {
		int tmp = start_pos.x;
		start_pos.x = start_pos.y;
		start_pos.y = tmp;
		tmp = end_pos.x;
		end_pos.x = end_pos.y;
		end_pos.y = tmp;
		steep = true;
	}
	if (start_pos.x>end_pos.x) {
		int tmp = start_pos.x;
		start_pos.x = end_pos.x;
		end_pos.x = tmp;
		tmp = start_pos.y;
		start_pos.y = end_pos.y;
		end_pos.y = tmp;
	}
	int dx = end_pos.x-start_pos.x;
	int dy = end_pos.y-start_pos.y;
	int derror2 = abs(dy)*2;
	int error2 = 0;
	int y = start_pos.y;
	for (int x=start_pos.x; x<=end_pos.x; x++)
	{
		for (int i = -line_width/2; i <= line_width/2; i++)
		{
			if (steep) {
			img_pix_put(img, y + i, x, color);
			// image->set(y, x, color);
			} else {
			//   image->set(x, y, );
			img_pix_put(img, x, y + i, color);
			}
		}
		error2 += derror2;
		if (error2 > dx) {
			y += (end_pos.y>start_pos.y?1:-1);
			error2 -= dx*2;
		}
	}
}
