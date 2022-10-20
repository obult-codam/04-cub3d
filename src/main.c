/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:06:09 by obult         #+#    #+#                 */
/*   Updated: 2022/10/20 17:04:29 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdlib.h>

// void	move_forward(t_data *data)
// {
// 	data->player.x += tan(data->angle) * 0.1; 
// }

// void	move_back(t_data *data)
// {
	
// }

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_D)
		data->angle = data->angle + 0.05;
	if (keydata.key == MLX_KEY_A)
		data->angle = data->angle - 0.05;
	// if (keydata.key == MLX_KEY_W)
	// 	move_forward(data);
	// if (keydata.key == MLX_KEY_D)
	// 	move_back(data);
}

int	the_simulation(t_data *data)
{
	// mlx_set_setting(MLX_MAXIMIZED, true);
	data->mlx = mlx_init(1024, 512, "cub3d", true);
	if (!data->mlx)
		return (1);

	data->img = mlx_new_image(data->mlx, 256, 256);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
		return (2);

	// mlx_resize_hook(data->mlx, &resize_hook, data);

	mlx_key_hook(data->mlx, &keyhook, data);
	mlx_loop_hook(data->mlx, frame_render, data);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}

int	main(void)
{
	t_data	data;
	char	**testmap = (char *[]){"1111", "10001", "10001", "10001", "11111"};

	data.textures[0] = mlx_load_png("./Cetusfinal.png");
	data.textures[1] = mlx_load_png("./P.png");
	data.textures[2] = data.textures[0];
	data.textures[3] = data.textures[1];
	data.angle = 0;
	data.map = testmap;
	data.x_max = 4;
	data.y_max = 4;
	data.player.x = 1.5;
	data.player.y = 1.5;
	data.ceiling = 0x0ffaf2ff;
	data.floor = 0xfaa00fff;

	the_simulation(&data);
}