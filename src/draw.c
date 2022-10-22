/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/22 12:51:15 by obult         #+#    #+#                 */
/*   Updated: 2022/10/22 13:20:50 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	draw_final(t_data *data, float distance, float hit, int pixel)
{
	int	i;
	int	wall_top;
	int	wall_bot;
	int	wall_size;

	i = 0;
	wall_size = data->mlx->height / positivef(distance);
	wall_top = (data->mlx->height - wall_size) / 2;
	wall_bot = data->mlx->height - wall_top;
	while (i < data->mlx->height)
	{
		if (i <= wall_top)
			mlx_put_pixel(data->img, pixel, i, data->ceiling);
		else if (i >= wall_bot)
			mlx_put_pixel(data->img, pixel, i, data->floor);
		else
			mlx_put_pixel(data->img, pixel, (float)i,
				get_texture_value(hit, (float)(i - wall_top)
					/ (float)wall_size, data->textures[data->side]));
		i++;
	}
}

void	draw_x_hit(t_data *data, float angle, float distance, int pixel)
{
	float	hit;
	float	integral;

	hit = modff(sinf(angle) * distance + data->player.x, &integral);
	if (hit < 0)
		hit = 1 + hit;
	if (is_north(angle))
		data->side = NORTH;
	else
	{
		hit = 1 - hit;
		data->side = SOUTH;
	}
	draw_final(data, distance * positivef(cosf(angle - data->angle)),
		hit, pixel);
}

void	draw_y_hit(t_data *data, float angle, float distance, int pixel)
{
	float	hit;

	hit = modff(sinf(angle - PI * 0.5) * distance + data->player.y, &hit);
	if (hit < 0)
		hit = 1 + hit;
	if (!is_east(angle))
	{
		data->side = WEST;
	}
	else
	{
		hit = 1 - hit;
		data->side = EAST;
	}
	draw_final(data, distance * positivef(cosf(angle - data->angle)),
		hit, pixel);
}

void	draw_vertical(t_data *data, int pixel)
{
	float	angle;
	float	distance;

	angle = atanf(((float)pixel - (data->mlx->width / 2))
			/ (data->mlx->width / 2)) + data->angle;
	distance = max_dist(data, angle);
	if (data->sign == 'x')
		draw_x_hit(data, angle, distance, pixel);
	else
		draw_y_hit(data, angle, distance, pixel);
}
