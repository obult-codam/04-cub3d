/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_render.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:19:43 by obult         #+#    #+#                 */
/*   Updated: 2022/10/21 18:52:22 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ray.h"
#include <stdio.h>
#include <stdlib.h>

uint32_t	get_texture_value(float x, float y, mlx_texture_t *tex)	// this could be a util
{
	uint32_t	dx;
	uint32_t	dy;
	uint32_t	result;
	uint32_t	end;
	uint32_t	*pixels;

	pixels = (uint32_t *)tex->pixels;
	dx = (uint32_t)round_down(tex->width * x);
	dy = (uint32_t)round_down(tex->height * y);
	if (dx >= tex->width || dy >= tex->height)
		return (0);
	result = pixels[(dx + dy * tex->width)];
	end = ((result>>24)&0xff) |
		((result<<8)&0xff0000) |
		((result>>8)&0xff00) |
		((result<<24)&0xff000000);
	return (end);
}

void	draw_final(t_data *data, float distance, float hit, int pixel, float angle)
{
	int	i;
	int	wall_top;
	int	wall_bot;
	int	wall_size;

	i = 0;
	distance = distance * positivef(cosf(angle - data->angle));
	(void)angle;
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
		{
			float		y = (float)(i - wall_top) / (float)wall_size;
			uint32_t tmp = get_texture_value(hit, y, data->textures[data->side]);
			mlx_put_pixel(data->img, pixel, (float)i, tmp);
		}
		i++;
	}
}

void	draw_x_hit(t_data *data, float angle, float distance, int pixel)
{
	float	hit;
	float	integral;

	hit = modff(sin(angle) * distance + data->player.x, &integral);
	if (hit < 0)
		hit = 1 + hit;
	if (angle > 1.5 * PI || angle < 0.5 * PI)
		data->side = NORTH;
	else
	{
		hit = 1 - hit;
		data->side = SOUTH;
	}
	draw_final(data, distance, hit, pixel, angle);
}

void	draw_y_hit(t_data *data, float angle, float distance, int pixel)
{
	float	hit;

	hit = modff(sin(angle - PI * 0.5) * distance + data->player.y, &hit);	// this has to be minus pl.y aparently..
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
	draw_final(data, distance, hit, pixel, angle);
}

void	draw_vertical(t_data *data, int pixel)
{
	float	angle;
	float	distance;

	angle = atanf(((float)pixel - (data->mlx->width / 2)) / (data->mlx->width / 2)) + data->angle;	// view
	distance = max_dist(data, angle);
	if (data->sign == 'x')
		draw_x_hit(data, angle, distance, pixel);
	else
		draw_y_hit(data, angle, distance, pixel);
}

void	resize_action(t_data *data)
{
	if (data->mlx->width == data->width && data->mlx->height == data->height)
		return ;
	if (!mlx_resize_image(data->img, data->mlx->width, data->mlx->height))
		exit(0);
	data->width = data->mlx->width;
	data->height = data->mlx->height;
	printf("resize action\n");
}

void	frame_render(void *param)
{
	t_data	*data;
	int		i;

	data = (t_data *)param;
	i = 0;
	data->angle = normalizePi(data->angle);
	resize_action(data);
	while (i < data->mlx->width)
	{
		draw_vertical(data, i);
		i++;
	}
}

