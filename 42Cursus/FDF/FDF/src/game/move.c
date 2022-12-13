#include "../../includes/fdf.h"

void	move_cells(t_map map, t_vector3 move_value)
{
	t_vector2	curr_pos;

	curr_pos.y = 0;
	while (curr_pos.y < map.size.y)
	{
		curr_pos.x = 0;
		while (curr_pos.x < map.size.x)
		{
			move_vector3(&map.cells[curr_pos.y][curr_pos.x].vect3, move_value);
			curr_pos.x++;
		}
		curr_pos.y++;
	}
}

void	move(bool *keypressed, t_map map)
{
	t_vector3	move_value;

	int	speed = 12;
	move_value = (t_vector3){0, 0, 0};
	if (keypressed[K_W])
		move_value.y -= speed;
	if (keypressed[K_S])
		move_value.y += speed;
	if (keypressed[K_A])
		move_value.x -= speed;
	if (keypressed[K_D])
		move_value.x += speed;

	move_cells(map, move_value);
}
