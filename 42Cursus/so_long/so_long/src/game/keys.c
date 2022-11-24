
#include "../../include/so_long.h"

void	init_keypressed(bool keypressed[200])
{
	int	i;

	i = 0;
	while (i < 200)
		keypressed[i++] = false;
}


int	on_keypress(int keycode, t_data *data)
{
	data->keypressed[keycode] = true;
	//printf("PR : %d\n", keycode);
	//write(1, "adasd", 1);
	//putnbr_fd(keysym, 1);
	if (keycode == K_ESC)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
	// int speed = 20;
	// if (keycode == K_W) // W
	// 	data->r1->x -= speed;
	// if (keycode == K_A) // A
	// 	data->r1->y -= speed;
	// if (keycode == K_S) // S
	// 	data->r1->y += speed;
	// if (keycode == K_D) // D
	// 	data->r1->x += speed;

	return (0);
}

int	on_keyrelease(int keycode, t_data *data)
{
	data->keypressed[keycode] = false;
	//printf("Re : %d\n", keycode);
	//write(1, "adasd", 1);
	//putnbr_fd(keysym, 1);
	// if (keycode == 0)
	// {
	// 	data->r1.x = 800;
	// 	data->r1.y = 800;
	// }
	return (0);
}
