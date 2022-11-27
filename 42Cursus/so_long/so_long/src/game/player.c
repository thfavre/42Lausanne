
#include "../../include/so_long.h"

void draw_player(struct s_player *self, t_img *img);
void move_player(struct s_player *self, t_obstacle *obstacles, bool *keypressed);

t_player create_player(t_rect rect)
{
	t_player	player;

	player.pos = (t_fvector2){rect.x, rect.y};
	player.rect = (t_rect){rect.x, rect.y, rect.width, rect.height, rgb(200, 2, 2)};
	player.vel = (t_fvector2){0, 0};
	player.gravity_dir = GRAV_DISABLE;
	player.gravity = 0.1;
	player.max_gravity = 10;
	player.move = move_player;
	player.draw = draw_player;
	return (player);
}

void draw_player(struct s_player *self, t_img *img)
{
	draw_rect(img, self->rect);
}

// void	jump_player(t_player *self)
// {
// 	if (self->on_ground)
// 		self->vel.y = -5;
// 		self->on_ground = false;
// }

void move_player(struct s_player *self, t_obstacle *obstacles, bool *keypressed)
{
	if (keypressed[K_W])
		self->gravity_dir = GRAV_UP;
	else if (keypressed[K_A])
		self->gravity_dir = GRAV_LEFT;
	else if (keypressed[K_S])
		self->gravity_dir = GRAV_DOWN;
	else if (keypressed[K_D])
		self->gravity_dir = GRAV_RIGHT;
	else if (keypressed[K_SPACE])
		self->gravity_dir = GRAV_DISABLE;


	if (self->gravity_dir == GRAV_DOWN)
	{
		if (self->vel.y < self->max_gravity)
			self->vel.y += self->gravity;
	}
	else if (self->gravity_dir == GRAV_UP)
	{
		if (self->vel.y > -self->max_gravity) // 10 = maxvel
			self->vel.y -= self->gravity;
	}
	else
	{
		if (self->vel.y > 0)
			self->vel.y -= self->gravity;
		else if (self->vel.y < 0)
			self->vel.y += self->gravity;
		if (self->vel.y < self->gravity && self->vel.y > -self->gravity)
			self->vel.y = 0;
	}

	if (self->gravity_dir == GRAV_RIGHT)
	{
		if (self->vel.x < self->max_gravity) // 10 = maxvel
			self->vel.x += self->gravity;
	}
	else if (self->gravity_dir == GRAV_LEFT)
	{
		if (self->vel.x > -self->max_gravity) // 10 = maxvel
			self->vel.x -= self->gravity;
	}
	else
	{
		if (self->vel.x > 0)
			self->vel.x -= self->gravity;
		else if (self->vel.x < 0)
			self->vel.x += self->gravity;
		if (self->vel.x < self->gravity && self->vel.x > -self->gravity)
			self->vel.x = 0;
	}


	printf("dir : %d  val: x %f   val: y %f\n", self->gravity_dir, self->vel.x, self->vel.y);

	player_collision_y(self, obstacles);
	// int	i;
	// if (self->vel.y != 0)
	// {
	// 	self->pos.y += self->vel.y;
	// 	self->rect.y = (int)self->pos.y;
	// 	i = 0;
	// 	while (i < 2)
	// 	{
	// 		if (colliderect(self->rect, obstacles[i].rect))
	// 		{
	// 			if (self->vel.y >= 0)
	// 				self->rect.y = obstacles[i].rect.y - self->rect.height;
	// 			else
	// 				self->rect.y = obstacles[i].rect.y + obstacles[i].rect.height;
	// 			self->vel.y = 0;
	// 			self->pos.y = (int)self->rect.y;
	// 		}
	// 		i++;
	// 	}
	// }
	player_collision_x(self, obstacles);

	//printf("p pos : %d\n", self->rect.x);
}
