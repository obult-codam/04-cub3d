/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:25:47 by obult         #+#    #+#                 */
/*   Updated: 2022/09/29 21:49:19 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <math.h>

/*
 *  this will shoot a ray and return the len in horizontal or vertical
 */

double	shoot_ray_h(t_data data, double angle, double x, double y)
{
	double	x_progress;
	double	y_distance;

	y_distance = modf(y, NULL);
	if (y_distance == 0)
		y_distance = 1;
	x_progress = sin(angle) * y_distance;
	if (data.map[round(y + y_distance)][round(x + x_progress)] != '0')
		return (x_progress / cos(angle));
	return (x_progress / cos(angle) + shoot_ray_h(data, angle, x + x_progress, y + y_distance));
}
