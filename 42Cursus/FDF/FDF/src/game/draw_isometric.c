#include "../../includes/fdf.h"

t_vector2	convert_vector3_to_isometric(t_vector3 vect3, double angle)
{
	t_vector2	vect2;

	// u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°);
	// v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°);
	vect2.x = vect3.x * cos(angle) + vect3.y * cos(angle + 2) + vect3.z * cos(angle - 2);
	vect2.y = vect3.x * sin(angle) + vect3.y * sin(angle + 2) + vect3.z * sin(angle - 2);

	return (vect2);
}

t_vector2	convert_vector3_to_parallel(t_vector3 vect3, float d)
{
    t_vector2 vect2;

    vect2.x = vect3.x / d;
    vect2.y = vect3.y / d;
    return vect2;
}

t_vector2 convert_vector3_to_conical(t_vector3 vect3, double angle)
{
	t_vector2 vect2;

	// u = x*cos(angle) + y*cos(angle + (180 - angle)/2) + z*cos(angle - (180 - angle)/2);
	// v = x*sin(angle) + y*sin(angle + (180 - angle)/2) + z*sin(angle - (180 - angle)/2);
	vect2.x = vect3.x * cos(angle) + vect3.y * cos(angle + (M_PI - angle) / 2) + vect3.z * cos(angle - (M_PI - angle) / 2);
	vect2.y = vect3.x * sin(angle) + vect3.y * sin(angle + (M_PI - angle) / 2) + vect3.z * sin(angle - (M_PI - angle) / 2);

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
				//start_pos = convert_vector3_to_isometric(apply_transformations(data, curr_pos.x, curr_pos.y), data->attributes.angle);
				//end_pos = convert_vector3_to_isometric(apply_transformations(data, curr_pos.x + 1, curr_pos.y), data->attributes.angle);
				//add_vector2_ip(&start_pos, data->attributes.offset);
				//add_vector2_ip(&end_pos, data->attributes.offset);
				start_pos = convert_vector3_to_conical(apply_transformations(data, curr_pos.x, curr_pos.y), data->attributes.angle);
				end_pos = convert_vector3_to_conical(apply_transformations(data, curr_pos.x + 1, curr_pos.y), data->attributes.angle);
				add_vector2_ip(&start_pos, data->attributes.offset);
				add_vector2_ip(&end_pos, data->attributes.offset);

				draw_line(&data->img, start_pos, end_pos, data->attributes.line_width, rgb(222 - curr_pos.y*15, 149, 57 + curr_pos.y * 15));
			}
			// draw the segment going to the down
			if (curr_pos.y < data->map.size.y - 1)
			{
				// start_pos = convert_vector3_to_isometric(apply_transformations(data, curr_pos.x, curr_pos.y), data->attributes.angle);
				// end_pos = convert_vector3_to_isometric(apply_transformations(data, curr_pos.x, curr_pos.y + 1), data->attributes.angle);
				// add_vector2_ip(&start_pos, data->attributes.offset);
				// add_vector2_ip(&end_pos, data->attributes.offset);
				start_pos = convert_vector3_to_conical(apply_transformations(data, curr_pos.x, curr_pos.y), data->attributes.angle);
				end_pos = convert_vector3_to_conical(apply_transformations(data, curr_pos.x, curr_pos.y + 1), data->attributes.angle);
				add_vector2_ip(&start_pos, data->attributes.offset);
				add_vector2_ip(&end_pos, data->attributes.offset);
				draw_line(&data->img, start_pos, end_pos,  data->attributes.line_width, rgb(222 - curr_pos.y*15, 149, 57 + curr_pos.y * 15));
			}
			curr_pos.x++;
		}
		curr_pos.y++;
	}
}
