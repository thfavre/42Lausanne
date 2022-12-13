
#include "../../include/so_long.h"

/* Returns an image with the sprite found in <path> */
t_img create_sprite(void *mlx, char *path)
{
	t_img	img;

	/* mlx function that creates and image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */
	img.mlx_img = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	// img.addr  = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	return (img);
}
