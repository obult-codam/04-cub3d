/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_render.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:19:43 by obult         #+#    #+#                 */
/*   Updated: 2022/10/18 16:56:53 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "ray.h"
#include <stdio.h>

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
	result = pixels[(dx + dy * tex->width)];
	end = ((result>>24)&0xff) |
		((result<<8)&0xff0000) |
		((result>>8)&0xff00) |
		((result<<24)&0xff000000);
	return (end);
}

void	draw_final(t_data *data, float distance, float hit, int pixel)
{
	int	i;
	int	wall_top;
	int	wall_bot;
	int	wall_size;

	i = 0;
	wall_size = data->mlx->height / distance;	// is this correct?, this needs to be changed with a modifier based on where it is on the screen
	wall_top = (data->mlx->height - wall_size) / 2;
	wall_bot = data->mlx->height - wall_top;
	while (i < data->mlx->height)
	{
		if (i < wall_top)
			mlx_put_pixel(data->img, pixel, i, data->ceiling);
		else if (i > wall_bot)
			mlx_put_pixel(data->img, pixel, i, data->floor);
		else
		{
			uint32_t tmp = get_texture_value(hit, (float)wall_size / (float)data->mlx->height * (float)i / (float)data->mlx->height, data->textures[data->side]);
			
			mlx_put_pixel(data->img, pixel, (float)i, tmp);
		}
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
	if (!((angle > -0.5 * PI && angle < 1.5 * PI) || angle > PI * 2.5))
	{
		hit = 1 - hit;
		data->side = SOUTH;
	}
	else
		data->side = NORTH;
	draw_final(data, distance, hit, pixel);
}

void	draw_y_hit(t_data *data, float angle, float distance, int pixel)
{
	float	hit;

	hit = modff(tan(angle - PI * 0.5) * distance, &hit);
	if (hit < 0)
		hit = 1 + hit;
	if (angle > 0 && angle < PI)
	{
		hit = 1 - hit;	// why do I reverse this??? (I think it is needed for tyhe west wall but could be for the east wall..)
		data->side = WEST;
	}
	else
		data->side = EAST;
	draw_final(data, distance, hit, pixel);
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
		i++;
	}
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		return ;
}

