/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:31:33 by obult         #+#    #+#                 */
/*   Updated: 2022/10/22 13:29:54 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub.h"

# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PI 3.1415926535
# define ERROR 2147483648

// Render and draws a vertical line of the whole frame on the horizontal pixel coordinate pixel
void	draw_vertical(t_data *data, int pixel);

// Distance calculation
float	max_dist(t_data *data, float angle);

// UTILS
int		round_down(float z);
float	positivef(float f);
float	calc_distance_y(float z, float angle);
float	calc_distance_x(float z, float angle);
float	normalize_pi(float f);

// Direction Utils
bool		is_north(float angle);
bool		is_east(float angle);

// Extract the pixel value out of the texture based on a 0 to 1 value on where it is in x and y coordinates
uint32_t	get_texture_value(float x, float y, mlx_texture_t *tex);

#endif