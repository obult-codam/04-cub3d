/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:13:29 by obult         #+#    #+#                 */
/*   Updated: 2022/10/25 21:29:35 by ieilat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "MLX42.h"
# include "parsing.h"

typedef enum e_side {
	NORTH,
	EAST,
	SOUTH,
	WEST,
}	t_side;

typedef struct s_player
{
	float	x;
	float	y;
}				t_player;

typedef struct s_data
{
	char			**map;
	int				x_max;
	int				y_max;
	char			sign;
	float			angle;
	uint32_t		ceiling;
	uint32_t		floor;
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*textures[4];
	bool			resize;
	t_side			side;
	int32_t			width;
	int32_t			height;
}				t_data;

/*
 *	Turns a t_map_struct into a t_data.
 *	Starts the game if no mlx_errors occur.
 *	Returns a positive integer upon error and zero upon succes.
 */
int		to_tomato_factory(t_map_struct ref);

/*
 *	Renders exactly one frame.
 *	Starts by checking if the player has moved or the window has been resized.
 */
void	frame_render(void *param);

/*
 *	This function checks keypresses and updates the data acordingly.
 */
void	key_check(t_data *data);

/*
 *	Executes mlx_terminate before exiting.
 */
void	complete_exit(void *param);

#endif
