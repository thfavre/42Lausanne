
#include "../../include/so_long.h"


bool	has_win(t_player *players, int players_nb);

// funtion that is called each frames
int	on_update(t_data *data)
{
	int	i;
	//render_background(data, rgb(0, 0, 100));
	draw_background(&data->img, rgb(222, 222, 222));
	//render_rect(&data->img, *(data->r1));
	//render_rect(&data->img, (t_rect){777, 77, 100, 100, rgb(111, 111, 100)});
	// player
	i = -1;
	while (++i < data->map.player_nb)
		data->map.players[i].draw(&data->map.players[i], &data->img, data->mlx_ptr);
	i = -1;
	while (++i < data->map.obst_nb)
		data->map.obstacles[i].draw(&(data->map.obstacles[i]), &data->img);
		//data->map.obstacles[i].draw(&data->map.obstacles[i], &data->img);
	if (!has_win(data->map.players, data->map.player_nb))
	{
		i = -1;
		while (++i < data->map.player_nb)
			data->map.players[i].move(&data->map.players[i], data->map.obstacles, data->map.obst_nb, data->keypressed);
		//data->player.move(&data->player, data->map.obstacles, data->map.obst_nb, data->keypressed);
	}
	else
	{
		printf("Vicotry\n");
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);



	return (0);
}

// Returns true if all players are colliding
bool	has_win(t_player *players, int players_nb)
{
	int	i;
	int	j;

	i = 0;
	while(i < players_nb)
	{
		j = i;
		while(j < players_nb)
		{
			if (&players[i] != &players[j])
			{
				//if (!colliderect(players[i].rect, players[j].rect))
				if (players[i].rect.x != players[j].rect.x || players[i].rect.y != players[j].rect.y)
				{
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
}
