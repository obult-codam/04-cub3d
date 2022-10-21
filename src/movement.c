/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 21:15:25 by obult         #+#    #+#                 */
/*   Updated: 2022/10/21 22:01:49 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ray.h"

void	move_forward(t_data *data)
{
	int	mod;

	mod = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		mod = 2;
	data->player.x += sinf(data->angle) * 0.05 * mod; 
	data->player.y += sinf(data->angle + 0.5 * PI) * 0.05 * mod;
}

void	move_back(t_data *data)
{
	int	mod;

	mod = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		mod = 2;
	data->player.x -= sinf(data->angle) * 0.05 * mod;
	data->player.y -= sinf(data->angle + 0.5 * PI) * 0.05 * mod; 
}

void	key_check(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->angle = data->angle + 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->angle = data->angle - 0.05;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_back(data);
}