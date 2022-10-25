/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tomato_factory.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:06:09 by obult         #+#    #+#                 */
/*   Updated: 2022/10/25 15:00:54 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"
#include <stdlib.h>
#include "libft.h"
#include "ray.h"

void	complete_exit(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_terminate(data->mlx);
	exit (0);
}

char	**rev_map(char **map)
{
	int		len;
	int		i;
	char	*tmp;

	i = 0;
	len = arr_len(map);
	while (i < len)
	{
		len--;
		tmp = map[i];
		map[i] = map[len];
		map[len] = tmp;
		i++;
	}
	return (map);
}

int	izaaks_tomato_factory(t_data *data)
{
	data->mlx = mlx_init(1024, 512, "cub3d", true);
	if (!data->mlx)
		return (1);
	data->img = mlx_new_image(data->mlx, 256, 256);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
		complete_exit(data);
	mlx_close_hook(data->mlx, complete_exit, data);
	mlx_loop_hook(data->mlx, frame_render, data);
	mlx_loop(data->mlx);
	return (0);
}

int	to_tomato_factory(t_map_struct ref)
{
	t_data	data;
	char	pv;

	// print_2d_array(ref.map);
	pv = ref.playerview;
	data.floor = (uint32_t)ref.floor;
	data.ceiling = (uint32_t)ref.ceiling;
	ft_memcpy(data.textures, ref.textures, 4 * sizeof(mlx_texture_t *));
	data.map = rev_map(ref.map);
	data.x_max = ref.with - 1;
	data.y_max = ref.height - 2;
	data.angle = 0.5 * PI * ((pv == 'E') + 2 * (pv == 'S') + 3 * (pv == 'W'));
	data.player.x = ref.playerx + 0.5;
	data.player.y = ref.height - ref.playery - 0.5;
	printf("%i\t%i\t%f\t%f\n", ref.height, ref.playery, data.player.y, data.player.x);
	print_2d_array(data.map);
	return(izaaks_tomato_factory(&data));
}
