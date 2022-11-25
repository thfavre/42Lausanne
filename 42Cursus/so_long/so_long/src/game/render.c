
#include "../../include/so_long.h"

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
	if (x >= 0 && x <= WINDOW_WIDTH && y >= 0 && y <= WINDOW_HEIGHT)
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
