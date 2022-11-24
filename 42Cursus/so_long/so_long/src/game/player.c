
#include "../../include/so_long.h"

void draw_player(struct s_player *self, t_img *img);
void move_player(struct s_player *self, bool *keypressed);

t_player create_player()
{
	struct s_player	player;

	player.move = move_player;
	player.velocity = PLAYER_VELOCITY;
	player.pos = (t_fvector2){500, 500};
	player.rect = (t_rect){player.pos.x, player.pos.y, 200, 200, rgb(200, 2, 2)};
	player.draw = draw_player;
	return (player);
}

void draw_player(struct s_player *self, t_img *img)
{
	render_rect(img, self->rect);
}

void move_player(struct s_player *self, bool *keypressed)
{
	t_fvector2	vect;

	printf("%d\n", keypressed[K_S]);
	vect = (t_fvector2) {0, 0};
	if (keypressed[K_W])
		vect.y -= self->velocity;
	if (keypressed[K_A])
		vect.x -= self->velocity;
	if (keypressed[K_S])
		vect.y += self->velocity;
	if (keypressed[K_D])
		vect.x += self->velocity;

	// check x collision
	self->pos.x += vect.x;
	// check y collision
	self->pos.y += vect.y;
	// update the rect
	self->rect.x = self->pos.x;
	self->rect.y = self->pos.y;
	//printf("p pos : %d\n", self->rect.x);
}
