#include "../../includes/fdf.h"

t_vector2	convert_vector3_to_isometric(t_vector3 vect3)
{
	t_vector2	vect2;
	double			angle;

	angle = 0.5;
	// u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°);
	// v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°);
	vect2.x = vect3.x * cos(angle) + vect3.y * cos(angle + 2) + vect3.z * cos(angle - 2);
	vect2.y = vect3.x * sin(angle) + vect3.y * sin(angle + 2) + vect3.z * sin(angle - 2);

	return (vect2);
}

void	draw_isometric(t_data *data)
{
	t_vector2	curr_pos;
	t_vector2	start_pos;
	t_vector2	end_pos;

	curr_pos.y = 0;
	while (curr_pos.y < data->map.size.y)
	{
		curr_pos.x = 0;
		while (curr_pos.x < data->map.size.x)
		{
			// draw the segment going to the right
			if (curr_pos.x < data->map.size.x - 1)
			{
				// start_pos = (t_vector2){data->map.cells[curr_pos.y][curr_pos.x].x, data->map.cells[curr_pos.y][curr_pos.x].y};
				// end_pos = (t_vector2){data->map.cells[curr_pos.y][curr_pos.x + 1].x, data->map.cells[curr_pos.y][curr_pos.x + 1].y};
				start_pos = convert_vector3_to_isometric(data->map.cells[curr_pos.y][curr_pos.x].vect3);
				end_pos = convert_vector3_to_isometric(data->map.cells[curr_pos.y][curr_pos.x + 1].vect3);
				//mult_vector2_int(&start_pos, data->map.zoom_factor);
				//mult_vector2_int(&end_pos, data->map.zoom_factor);
				// printf("start %d %d\n", start_pos.x, start_pos.y);
				// printf("end %d %d\n\n", end_pos.x, end_pos.y);
				draw_line(&data->img, start_pos, end_pos, 1, rgb(170, 149, 57));
			}
			// draw the segment going to the down
			if (curr_pos.y < data->map.size.y - 1)
			{
				// start_pos = (t_vector2){data->map.cells[curr_pos.y][curr_pos.x].x, data->map.cells[curr_pos.y][curr_pos.x].y};
				// end_pos = (t_vector2){data->map.cells[curr_pos.y + 1][curr_pos.x].x, data->map.cells[curr_pos.y + 1][curr_pos.x].y};
				start_pos = convert_vector3_to_isometric(data->map.cells[curr_pos.y][curr_pos.x].vect3);
				end_pos = convert_vector3_to_isometric(data->map.cells[curr_pos.y + 1][curr_pos.x].vect3);
				//mult_vector2_int(&start_pos, data->map.zoom_factor);
				//mult_vector2_int(&end_pos, data->map.zoom_factor);
				draw_line(&data->img, start_pos, end_pos, 1, rgb(170, 149, 57));
			}
			curr_pos.x++;
		}
		curr_pos.y++;
	}
}
