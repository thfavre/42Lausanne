
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

void draw_line(int x0, int y0, int x1, int y1, t_img *img, int color)
{
	bool steep = false;
	if (abs(x0-x1)<abs(y0-y1)) {
		int tmp = x0;
		x0 = y0;
		y0 = tmp;
		tmp = x1;
		x1 = y1;
		y1 = tmp;
		steep = true;
	}
	if (x0>x1) {
		int tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	int dx = x1-x0;
	int dy = y1-y0;
	int derror2 = abs(dy)*2;
	int error2 = 0;
	int y = y0;
	for (int x=x0; x<=x1; x++) {
		if (steep) {
		img_pix_put(img, y, x, color);
		// image->set(y, x, color);
		} else {
		//   image->set(x, y, );
		img_pix_put(img, x, y, color);
		}
		error2 += derror2;
		if (error2 > dx) {
			y += (y1>y0?1:-1);
			error2 -= dx*2;
		}
	}
}
