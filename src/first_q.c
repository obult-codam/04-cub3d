/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_q.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:22:22 by obult         #+#    #+#                 */
/*   Updated: 2022/10/05 16:13:18 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

static float	calc_distance_y(float y)
{
	float	tmp;
	float	trash;

	tmp = modff(y, &trash);
	return (1 - tmp);
}

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the x axis.
 */
static float	max_x_dist(t_data data, float angle, float x, float y)
{
	float	y_dist;
	float	x_dist;
	float	result;

	y_dist = calc_distance_y(y);
	x_dist = tanf(angle) * y_dist;
	if ((int)roundf(y_dist + y) > data.y_max || (int)roundf(y_dist + y) < 0)
		return (ERROR);
	if ((int)roundf(x_dist + x) > data.x_max || (int)roundf(x_dist + x) < 0)
		return (ERROR);
	if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist)] != '0')
		return (x_dist);
	result = max_x_dist(data, angle, x + x_dist, y + y_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + x_dist);
}


static float	calc_distance_x(float x)
{
	float	tmp;
	float	trash;

	tmp = modff(x, &trash);
	return (1 - tmp);
}

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the y axis.
 */
static float	max_y_dist(t_data data, float angle, float x, float y)
{
	float	y_dist;
	float	x_dist;
	float	result;

	x_dist = calc_distance_x(x);
	y_dist = tanf(angle - (0.5 * PI)) * x_dist;
	if ((int)roundf(y_dist + y) > data.y_max || (int)roundf(y_dist + y) < 0)
		return (ERROR);
	if ((int)roundf(x_dist + x) > data.x_max || (int)roundf(x_dist + x) < 0)
		return (ERROR);
	if (data.map[(int)roundf(y + y_dist)][(int)roundf(x + x_dist)] != '0')
		return (y_dist);
	result = max_y_dist(data, angle, x + x_dist, y + y_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + y_dist);
}

float	first_q(t_data *data, float angle)
{
	float	x_total;
	float	y_total;

	x_total = max_x_dist(*data, angle, data->player.x, data->player.y);
	y_total = max_y_dist(*data, angle, data->player.x, data->player.y);
	if (x_total == ERROR && y_total == ERROR)
		return (ERROR);
	if (positivef(x_total) < positivef(y_total))
	{
		data->sign = 'x';
		return (x_total / sinf(angle));
	}
	data->sign = 'y';
	return (y_total / sinf(angle - (PI * 0.5)));
}