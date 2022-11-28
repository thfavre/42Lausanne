
#include "../../include/so_long.h"

void	draw_obstacle(struct s_obstacle *self, t_img *img);

t_obstacle create_obstacle(t_rect rect)
{
	t_obstacle	obstacle;

	obstacle.rect = rect;
	obstacle.draw = draw_obstacle;
	return (obstacle);
}

void	draw_obstacle(struct s_obstacle *self, t_img *img)
{
	draw_rect(img, self->rect);
}
