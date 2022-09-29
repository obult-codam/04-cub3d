/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 17:31:33 by obult         #+#    #+#                 */
/*   Updated: 2022/09/29 21:32:03 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

// typedef struct	s_angle
// {
// 	double	horizontal;
// 	double	vertical;
// }				t_angle;

enum direction{
	N,
	E,
	S,
	W,
};

typedef struct	s_player
{
	double	h_coord;
	double	v_coord;
}				t_player;

typedef struct	s_data
{
	char		**map;
	t_player	player;
}				t_data;


#endif