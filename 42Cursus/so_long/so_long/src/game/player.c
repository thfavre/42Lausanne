
#include "../../include/so_long.h"

void draw_player(struct s_player *self, t_img *img);
void move_player(struct s_player *self, t_obstacle *obstacles, int obst_nb, bool *keypressed);

t_player create_player(t_rect rect, void *mlx)
{
	t_player	player;

	player.pos = (t_fvector2){rect.x, rect.y};
	player.rect = (t_rect){rect.x, rect.y, rect.width, rect.height, rgb(200, 2, 2)};
	//player.img = create_sprite(mlx, "../../assets/80/bread_down.xpm");
	player.vel = (t_fvector2){0, 0};
	player.gravity_dir = GRAV_DISABLE;
	player.gravity = 0.15;
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

void	make_gravity_y(t_player *self)
{
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
}

void	make_gravity_x(t_player *self)
{
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
}

void move_player(struct s_player *self, t_obstacle *obstacles, int obst_nb, bool *keypressed)
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

	make_gravity_y(self);
	make_gravity_x(self);
	player_collision_y(self, obstacles, obst_nb);
	player_collision_x(self, obstacles, obst_nb);
}
