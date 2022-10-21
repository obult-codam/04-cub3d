/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   direction_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 18:20:49 by obult         #+#    #+#                 */
/*   Updated: 2022/10/21 18:27:05 by obult         ########   odam.nl         */
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