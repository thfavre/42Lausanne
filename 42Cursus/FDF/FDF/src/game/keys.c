
#include "../../includes/fdf.h"

void	init_keypressed(bool keypressed[400])
{
	int	i;

	i = 0;
	while (i < 400)
		keypressed[i++] = false;
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode < 400)
		data->keypressed[keycode] = true;
	//printf("%d\n", keycode);
	if (keycode == K_ESC)
		{
			close_mlx(data);
			//data->win_ptr = NULL;
		}
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
	if (keycode < 400)
		data->keypressed[keycode] = false;
	return (0);
}

// int	get_mouse_input(int key, int x, int y, t_fract *f)
// {
// 	if (key == M_ZOOM_IN || key == M_ZOOM_OUT)
// 		zoom(key, x, y, f);
// 	draw(f);
// 	return (0);
// }

int	close_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (1);
}
