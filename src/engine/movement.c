/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 21:15:25 by obult         #+#    #+#                 */
/*   Updated: 2022/10/25 17:54:01 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ray.h"

void	move(t_data *data, float x, float y)
{
	int	mod;
	int	rx;
	int	ry;

	mod = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT))
		mod = 2;
	x = x * mod + data->player.x;
	y = y * mod + data->player.y;
	rx = round_down(x);
	ry = round_down(y);
	if (ry >= 0 && ry < data->y_max && rx >= 0 && rx < data->x_max)
	{
		if (data->map[ry][rx] != 'X')
			return ;
	}
	else
		return ;
	data->player.x = x;
	data->player.y = y;
}

void	key_check(t_data *data)
{
	float	dt;

	dt = (float)data->mlx->delta_time * 3;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->angle = data->angle + dt;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->angle = data->angle - dt;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move(data, sinf(data->angle) * dt, sinf(data->angle + 0.5 * PI)
			* dt);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move(data, sinf(data->angle) * - dt, sinf(data->angle + 0.5 * PI)
			* - dt);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move(data, sinf(data->angle - 0.5 * PI) * dt, sinf(data->angle)
			* dt);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move(data, sinf(data->angle - 0.5 * PI) * - dt, sinf(data->angle)
			* - dt);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		complete_exit(data);
}
