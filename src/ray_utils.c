/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 13:53:25 by obult         #+#    #+#                 */
/*   Updated: 2022/10/10 14:01:43 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

/*
 *	Always returns a positive value
 */
float	positivef(float f)
{
	if (f < 0)
		return (f * -1);
	return (f);
}

/*
 *	Round down a float, because roundf() rounds to the nearest int.
 *	This is needed to consistently pick the right box to check for a wall!
 */
int	round_down(float z)
{
	float	trash;
	float	tmp;

	trash = modff(z, &tmp);
	(void)trash;
	return ((int)tmp);
}

/*
 *  These functions calculates the distance towards the cell border over an axis.
 *	The angle is needed to return a negative number for back- and downwards.
 */
float	calc_distance_y(float z, float angle)
{
	float	tmp;
	float	trash;

	tmp = modff(z, &trash);
	if (angle > 0.5 * PI && angle < 1.5 * PI)
	{
		if (!tmp)
			return (-1);
		return (-1 * tmp);
	}
	return (1 - tmp);
}

float	calc_distance_x(float z, float angle)
{
	float	tmp;
	float	trash;

	tmp = modff(z, &trash);
	if (angle > 0 && angle < PI)
		return (1 - tmp);
	if (!tmp)
		return (-1);
	return (tmp * -1);
}
