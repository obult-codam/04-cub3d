/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 13:53:25 by obult         #+#    #+#                 */
/*   Updated: 2022/10/22 13:29:39 by obult         ########   odam.nl         */
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
 *	it normalizes to a value between 0 and 2 PI
 */
float	normalize_pi(float f)
{
	while (f < 0 || f > 2 * PI)
	{
		if (f < 0)
			f += 2 * PI;
		else
			f -= 2 * PI;
	}
	return (f);
}

/*
 *	Round down a float, because roundf() rounds to the nearest int.
 *	This is needed to consistently pick the right box to check for a wall!
 */
int	round_down(float z)
{
	float	tmp;

	modff(z, &tmp);
	return ((int)tmp);
}

/*
 *  These functions calculates the distance towards the cell border over an axis.
 *	The angle is needed to return a negative number for back- and downwards.
 */
float	calc_distance_y(float z, float angle)
{
	float	tmp;

	tmp = modff(z, &tmp);
	if (!is_north(angle))
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

	tmp = modff(z, &tmp);
	if (is_east(angle))
		return (1 - tmp);
	if (!tmp)
		return (-1);
	return (tmp * -1);
}
