
#include "../../include/so_long.h"

void draw_player(struct s_player *self, t_img *img);
void move_player(struct s_player *self, t_obstacle obstacle, bool *keypressed);

t_player create_player(t_rect rect)
{
	t_player	player;

	player.pos = (t_fvector2){rect.x, rect.y};
	player.rect = (t_rect){rect.x, rect.y, rect.width, rect.height, rgb(200, 2, 2)};
	player.move_speed = 10;
	player.velocity = (t_fvector2){PLAYER_VELOCITY, PLAYER_VELOCITY/2};
	player.on_ground = false;
	player.move = move_player;
	player.draw = draw_player;
	return (player);
}

void draw_player(struct s_player *self, t_img *img)
{
	draw_rect(img, self->rect);
}

void	jump_player(t_player *self)
{
	if (self->on_ground)
		self->velocity.y = -3;
		self->on_ground = false;
}

void move_player(struct s_player *self, t_obstacle obstacle, bool *keypressed)
{
	t_fvector2	vect;

	vect = (t_fvector2) {0, 0};
	if (keypressed[K_D])
		vect.x += self->move_speed;
	if (keypressed[K_A])
		vect.x -= self->move_speed;
	if (keypressed[K_W] || keypressed[K_SPACE])
		jump_player(self);
	vect.y += self->velocity.y;
	if (self->velocity.y < 10) // 4 = maxvel
		self->velocity.y += 0.09;
	// if (self->on_ground)
	// 	vect.y = 0;
		//vect.y -= self->velocity.y;
	// if (keypressed[K_S])
	// 	vect.y += self->velocity.y;

	self->pos.y += vect.y;

	//self->rect.y += vect.y;
	printf("self :d%d f%f  v%f\n", self->rect.y, self->pos.y, vect.y);
	if (colliderect(self->rect, obstacle.rect))
	{
		printf("I AM Collidinf\n");
		if (vect.y > 0)
		{
			self->pos.y = obstacle.rect.y - self->rect.height;
			self->on_ground = true;
			printf("I HAVE TOUCH THE GROUND\n");
		}
		else if (vect.y < 0)
			self->pos.y = obstacle.rect.y + obstacle.rect.height;
	}
	self->rect.y = (int)self->pos.y;


	self->pos.x += vect.x;
	self->rect.x += vect.x;
	printf("%f %f\td%d f%f %d\n", vect.x, vect.y, self->rect.y,self->pos.y, colliderect(self->rect, obstacle.rect));
	if (colliderect(self->rect, obstacle.rect))
		exit(1);
	if (colliderect(self->rect, obstacle.rect))
	{
		if (vect.x > 0)
			self->pos.x = obstacle.rect.x - self->rect.width;
		else if (vect.x < 0)
			self->pos.x = obstacle.rect.x + obstacle.rect.width;
	}
	self->rect.x = self->pos.x;
	// check y collision

	//printf("p pos : %d\n", self->rect.x);
}
