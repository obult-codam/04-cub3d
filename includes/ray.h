/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:31:33 by obult         #+#    #+#                 */
/*   Updated: 2022/10/11 12:15:19 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub.h"

# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define PI 3.1415926535
# define ERROR 2147483648



// Distance calculation
float	max_dist(t_data *data, float angle);

// UTILS
int		round_down(float z);
float	positivef(float f);
float	calc_distance_y(float z, float angle);
float	calc_distance_x(float z, float angle);

#endif