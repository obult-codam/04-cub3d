/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/10/21 21:59:53 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the x axis.
 */
float	max_x_dist(t_data data, float angle, float x, float y)
{
	float	x_dist;
	float	y_dist;
	float	result;

	y_dist = calc_distance_y(y, angle);
	x_dist = tanf(angle) * y_dist;
	if (round_down(x_dist + x) > data.x_max || round_down(x_dist + x) < 0)
		return (ERROR);
	if (round_down(y_dist + y) > data.y_max || round_down(y_dist + y) < 0)
		return (ERROR);
	if (is_north(angle))
		if (data.map[round_down(y + y_dist)][round_down(x + x_dist)] != '0')
			return (x_dist);
	if (round_down(y_dist + y) < 1)
		return (ERROR);
	if (data.map[round_down(y + y_dist) - 1][round_down(x + x_dist)] != '0')
		return (x_dist);
	result = max_x_dist(data, angle, x + x_dist, y + y_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + x_dist);
}

// float	new_max_y_dist(t_data data, float angle, float x, float y)
// {
// 	if
// }

/*
 *	This Function calculates the distance untill a ray with an angle against the north
 *	has reached an obstacle perpendicular with the y axis.
 */
float	max_y_dist(t_data data, float angle, float x, float y)
{
	float	y_dist;
	float	x_dist;
	float	result;
	float	anglePI;

	anglePI = angle - (PI * 0.5);
	x_dist = calc_distance_x(x, angle);
	y_dist = tanf(anglePI) * x_dist * -1;
	if (round_down(y_dist + y) > data.y_max || round_down(y_dist + y) < 0)
		return (ERROR);
	if (round_down(x_dist + x) > data.x_max || round_down(x_dist + x) < 0)
		return (ERROR);
	if (is_east(angle))
		if (data.map[round_down(y + y_dist)][round_down(x + x_dist)] != '0')
			return (y_dist);
	if (round_down(x_dist + x) < 1)
		return (ERROR);
	if (data.map[round_down(y + y_dist)][round_down(x + x_dist) - 1] != '0')	//
		return (y_dist);
	result = max_y_dist(data, angle, x + x_dist, y + y_dist);
	if (result == ERROR)
		return (ERROR);
	return (result + y_dist);
}

/*
 *	This function needs to be called to get the distance to the first wall
 *	Also the sign char in struct will be set to 'x' or 'y' depending on where it hit
 */
float	max_dist(t_data *data, float angle)
{
	float	x_total;
	float	y_total;

	if (angle == 0)
		angle = 0.001;
	x_total = max_x_dist(*data, angle, data->player.x, data->player.y) / sinf(angle);
	y_total = max_y_dist(*data, angle, data->player.x, data->player.y) / sinf(angle - PI * 0.5);
	if (x_total == ERROR && y_total == ERROR)
		return (ERROR);
	if (positivef(x_total) < positivef(y_total))
	{
		data->sign = 'x';
		return (x_total);
	}
	data->sign = 'y';
	return (y_total);
}
