#include "../../include/so_long.h"


void	draw_collectible(struct s_collectible *self, t_img *img);

t_collectible create_colletible(t_rect rect)
{
	t_collectible	collectible;

	collectible.rect = rect;
	collectible.draw = draw_collectible;
	collectible.is_collected = false;
	return (collectible);
}

void	draw_collectible(struct s_collectible *self, t_img *img)
{
	draw_rect(img, self->rect);
}
