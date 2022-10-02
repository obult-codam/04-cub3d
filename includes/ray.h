/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:31:33 by obult         #+#    #+#                 */
/*   Updated: 2022/10/02 13:44:30 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <limits.h>

# define PI 3.1415926535
# define ERROR 2147483648

// typedef struct	s_angle
// {
// 	float	horizontal;
// 	float	vertical;
// }				t_angle;

enum direction{
	N,
	E,
	S,
	W,
};

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


#endif