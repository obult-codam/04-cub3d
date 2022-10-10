/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:31:33 by obult         #+#    #+#                 */
/*   Updated: 2022/10/10 14:28:10 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define PI 3.1415926535
# define ERROR 2147483648

typedef struct	s_player
{
	float	x;
	float	y;
}				t_player;

typedef struct	s_data
{
	char		**map;
	int			x_max;
	int			y_max;
	char		sign;
	t_player	player;
}				t_data;

// Distance calculation
float	max_dist(t_data *data, float angle);

// UTILS
int		round_down(float z);
float	positivef(float f);
float	calc_distance_y(float z, float angle);
float	calc_distance_x(float z, float angle);

#endif