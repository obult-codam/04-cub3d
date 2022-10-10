/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:06:09 by obult         #+#    #+#                 */
/*   Updated: 2022/10/10 18:38:19 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "ray.h"

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(void)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(256, 256, "windows", true);
	if (!mlx)
		return (0);

	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (0);

	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}