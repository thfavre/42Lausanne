#include "../../includes/fdf.h"

void	zoom(t_map map, double zoom_factor) // TODO create a function to apply a function to add cells??
{
	t_vector2	curr_pos;

	curr_pos.y = 0;
	while (curr_pos.y < map.size.y)
	{
		curr_pos.x = 0;
		while (curr_pos.x < map.size.x)
		{
			//move_vector3(&map.cells[curr_pos.y][curr_pos.x].vect3, move_value);
			curr_pos.x++;
			map.cells[curr_pos.y][curr_pos.x].vect3.x *= zoom_factor;
			map.cells[curr_pos.y][curr_pos.x].vect3.y *= zoom_factor;
			printf("%d, \n", map.cells[curr_pos.y][curr_pos.x].vect3.y);
		}
		curr_pos.y++;
	}
}
