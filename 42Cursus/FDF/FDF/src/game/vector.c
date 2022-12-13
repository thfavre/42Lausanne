#include "../../includes/fdf.h"

/* move in place*/
void	move_vector3(t_vector3 *vect3, t_vector3 move_vect3)
{
	vect3->x += move_vect3.x;
	vect3->y += move_vect3.y;
	vect3->z += move_vect3.z;
}

void	mult_vector2_int(t_vector2 *vect2, int mult)
{
	vect2->x *= mult;
	vect2->y *= mult;
}
