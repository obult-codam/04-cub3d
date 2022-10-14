/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_render.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:19:43 by obult         #+#    #+#                 */
/*   Updated: 2022/10/13 16:12:50 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ray.h"
#include <stdio.h>

uint32_t	get_texture_value(float x, float y, mlx_texture_t *tex)
{
	uint32_t	dx;
	uint32_t	dy;

	dx = (uint32_t)round_down(tex->width * x);
	dy = (uint32_t)round_down(tex->height * y);
	return ((uint23_t)tex->pixels[(dx + dy * tex->width)]);
}

void	draw_x_final(t_data *data, float distance, float hit, int pixel)
{
	int	i;
	int	wall_top;
	int	wall_bot;

	i = 0;
	wall_top = / distance;	// also needs to be done
	while (i < data->mlx->height)
	{
		if (i < wall_top)
			mlx_put_pixel(data->img, pixel, i, data->ceiling);
		else if (i > wall_bot)
			mlx_put_pixel(data->img, pixel, i, data->floor);
		else
			mlx_put_pixel(data->img, pixel, i, get_texture_value(hit, (float)(wall_bot - wall_top) / (float)(i - wall_top), data->textures[data->side]));	// needs to get color value
		i++;
	}
}

void	draw_x_hit(t_data *data, float angle, float distance, int pixel)
{
	float	hit;
	float	integral;


	hit = modff(tan(angle) * distance, &integral);
	if (hit < 0)
		hit = 1 + hit;
	if (!(angle > -0.5 * PI && angle < 1.5 * PI || angle > PI * 2.5))
	{
		hit = 1 - hit;
		data->side = SOUTH;
	}
	else
		data->side = NORTH;
	draw_x_final(data, distance, hit, pixel);
}

void	draw_vertical(t_data *data, int pixel)
{
	float	angle;
	float	distance;

	angle = atanf(((float)pixel - (data->mlx->width / 2)) / (data->mlx->width / 2)) + data->angle;
	distance = max_dist(data, angle);
	if (data->sign == 'x')
		draw_x_hit(data, angle, distance, pixel);
	else
		draw_y_hit(data, angle, distance, pixel);
}

void	frame_render(void *param)
{
	t_data	*data;
	int		i;

	data = (t_data *)param;
	i = 0;
	printf("WIDTH: %d | HEIGHT: %d\n", data->mlx->width, data->mlx->height);
	data->img = mlx_new_image(data->mlx, data->mlx->width, data->mlx->height);	// I shoud not create this many new images
	if (!data->img)
		return ;
	while (i < data->mlx->width)
	{
		draw_vertical(data, i);
		// mlx_put_pixel(data->img, i, 15, 0xFF0000FF);
		i++;
	}
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		return ;
}

