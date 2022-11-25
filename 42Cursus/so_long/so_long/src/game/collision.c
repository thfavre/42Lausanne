
#include "../../include/so_long.h"

bool	colliderect(t_rect rect1, t_rect rect2)
{
	if (rect1.x < rect2.x + rect2.width && rect1.x + rect1.width > rect2.x)
		if (rect1.y < rect2.y + rect2.height && rect1.y + rect1.height > rect2.y)
		return (true);
	// if (rect1.x >= rect2.x && rect1.x <= rect2.x + rect2.width)
	// 	if (rect1.y >= rect2.y && rect1.y <= rect2.x + rect2.height)
	// 		return (true);
	return (false);
}
