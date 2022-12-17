#include "../../includes/fdf.h"

/* move in place*/
void	move_vector3_ip(t_vector3 *vect3, t_vector3 move_vect3)
{
	vect3->x += move_vect3.x;
	vect3->y += move_vect3.y;
	vect3->z += move_vect3.z;
}

void	mult_vector2_int_ip(t_vector2 *vect2, int mult)
{
	vect2->x *= mult;
	vect2->y *= mult;
}

t_vector3	mult_vector3_float(t_vector3 vect3, float mult)
{
	t_vector3	new_vect3;
	new_vect3.x = vect3.x * mult;
	new_vect3.y = vect3.y * mult;
	new_vect3.z = vect3.z * mult;
	return (new_vect3);
}

t_vector3	mult_vector3_dvector3(t_vector3 vect3, t_dvector3 mult_vect3)
{
	t_vector3	new_vect3;
	new_vect3.x = vect3.x * mult_vect3.x;
	new_vect3.y = vect3.y * mult_vect3.y;
	new_vect3.z = vect3.z * mult_vect3.z;
	return (new_vect3);
}

void	add_vector2_ip(t_vector2 *vect, t_vector2 add_vect)
{
	vect->x += add_vect.x;
	vect->y += add_vect.y;
}
