
#include "../../include/so_long.h"

bool	colliderect(t_rect rect1, t_rect rect2)
{
	if (rect1.x < rect2.x + rect2.width && rect1.x + rect1.width > rect2.x)
		if (rect1.y < rect2.y + rect2.height && rect1.y + rect1.height > rect2.y)
		return (true);
	// if (rect1.x >= rect2.x && rect1.x <= rect2.x + rect2.width)
	// 	if (rect1.y >= rect2.y && rect1.y <= rect2.x + rect2.height)
	// 		return (true);
	return (false);
}

void	player_collision_y(t_player *self, t_obstacle *obstacles)
{
	int	i;
	if (self->vel.y != 0)
	{
		self->pos.y += self->vel.y;
		self->rect.y = (int)self->pos.y;
		i = 0;
		while (i < 2)
		{
			if (colliderect(self->rect, obstacles[i].rect))
			{
				if (self->vel.y >= 0)
					self->rect.y = obstacles[i].rect.y - self->rect.height;
				else
					self->rect.y = obstacles[i].rect.y + obstacles[i].rect.height;
				self->vel.y = 0;
				self->pos.y = (int)self->rect.y;
			}
			i++;
		}
	}
}

void	player_collision_x(t_player *self, t_obstacle *obstacles)
{
	int	i;

	if (self->vel.x != 0)
	{
		self->pos.x += self->vel.x;
		self->rect.x = (int)self->pos.x;
		i = 0;
		while (i < 2)
		{
			if (colliderect(self->rect, obstacles[i].rect))
			{
				if (self->vel.x >= 0)
					self->rect.x = obstacles[i].rect.x - self->rect.width;
				else
					self->rect.x = obstacles[i].rect.x + obstacles[i].rect.width;
				self->vel.x = 0;
				self->pos.x = self->rect.x;
			}
			i++;
		}
	}
}
