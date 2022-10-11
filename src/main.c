/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:06:09 by obult         #+#    #+#                 */
/*   Updated: 2022/10/11 14:12:14 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// 	// 
// }

int	main(void)
{
	t_data	data;

	data.angle = 0;
	mlx_set_setting(MLX_MAXIMIZED, true);
	data.mlx = mlx_init(256, 256, "cub3d", true);
	if (!data.mlx)
		return (1);

	data.img = mlx_new_image(data.mlx, 256, 256);
	if (!data.img || (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0))
		return (2);

	mlx_put_pixel(data.img, 0, 0, 0xFF0000FF);
	mlx_loop_hook(data.mlx, frame_render, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}