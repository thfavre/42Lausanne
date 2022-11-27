/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:45:00 by thfavre           #+#    #+#             */
/*   Updated: 2022/11/23 11:01:32 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	win = mlx_new_window(mlx, 1920, 1080, "Trop style");
	if (win == NULL)
	{
		free(mlx);
		return (1);
	}
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	
	



	int i = 0;
	int j = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 100)
		{
			mlx_pixel_put(mlx, win, 200+i, 200+j, 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
