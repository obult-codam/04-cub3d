/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 18:20:49 by obult         #+#    #+#                 */
/*   Updated: 2022/10/22 13:09:04 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ray.h"

bool	is_north(float angle)
{
	return ((angle > -0.5 * PI && angle < 0.5 * PI) || angle > 1.5 * PI);
}

bool	is_east(float angle)
{
	return ((angle > 0 && angle < PI) || angle > 2 * PI);
}

uint32_t	get_texture_value(float x, float y, mlx_texture_t *tex)
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
	end = ((result >> 24) & 0xff)
		| ((result << 8) & 0xff0000)
		| ((result >> 8) & 0xff00)
		| ((result << 24) & 0xff000000);
	return (end);
}
