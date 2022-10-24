/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ieilat <ieilat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 19:19:21 by ieilat        #+#    #+#                 */
/*   Updated: 2022/10/24 16:23:31 by ieilat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "MLX42.h"

typedef struct s_map_struct
{
	char			**input;
	char			**map;
	char			**config;
	int				with;
	int				height;
	int				playerx;
	int				playery;
	int				north;
	int				south;
	int				west;
	int				east;
	long			floor;
	long			ceiling;
	char			playerview;
	int				check;
	mlx_texture_t	*textures[4];

}			t_map_struct;

void	file_parser(t_map_struct *ms, int fd);
void	flood_map(t_map_struct *ms);
void	config_check(t_map_struct *ms);
char	**split_mapstr(t_map_struct *ms, const char *str, char c);
void	init_textures(t_map_struct *ms);
void	check_north_south(char c, t_map_struct *ms, int x, int y);

#endif 
