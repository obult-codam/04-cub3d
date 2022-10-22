/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame_render.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:19:43 by obult         #+#    #+#                 */
/*   Updated: 2022/10/22 13:30:34 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/*
 *	Checks if the window has been resized and resizes the imag if needed.
 */
void	resize_action(t_data *data)
{
	if (data->mlx->width == data->width && data->mlx->height == data->height)
		return ;
	if (!mlx_resize_image(data->img, data->mlx->width, data->mlx->height))
		exit(0);
	data->width = data->mlx->width;
	data->height = data->mlx->height;
}

/*
 *	Renders exactly one frame.
 *	Starts by checking if the player has moved or the window has been resized.
 */
void	frame_render(void *param)
{
	t_data	*data;
	int		i;

	data = (t_data *)param;
	i = 0;
	key_check(data);
	resize_action(data);
	data->angle = normalize_pi(data->angle);
	while (i < data->mlx->width)
	{
		draw_vertical(data, i);
		i++;
	}
}
