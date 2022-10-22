/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:13:29 by obult         #+#    #+#                 */
/*   Updated: 2022/10/22 13:14:13 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "MLX42.h"

typedef enum {
	NORTH,
	EAST,
	SOUTH,
	WEST,
}	t_side;

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
	float		angle;
	uint32_t	ceiling;
	uint32_t	floor;
	t_player	player;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_side			side;
	mlx_texture_t	*textures[4];
	bool			resize;
	int32_t		width;
	int32_t		height;
}				t_data;

/*
 *	Renders exactly one frame.
 *	Starts by checking if the player has moved or the window has been resized.
 */
void	frame_render(void *param);

/*
 *	This function checks keypresses and updates the data acordingly.
 */
void	key_check(t_data *data);

#endif