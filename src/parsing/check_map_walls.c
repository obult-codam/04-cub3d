/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map_walls.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ieilat <ieilat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:51:07 by ieilat        #+#    #+#                 */
/*   Updated: 2022/10/25 18:37:27 by ieilat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include "libft.h"

void	newline_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '1' || str[i + 1] == '0'))
		{
			while (str[i])
			{
				if (str[i] == '\n' && (str[i + 1] == '\n' ))
					error_and_msg("Consecutive Newlines", 2);
				i++;
			}
		}
		i++;
	}
}

void	check_north_south(char c, t_map_struct *ms, int x, int y)
{
	if (c == 'N')
	{
		(ms->check)++;
		ms->playerx = x;
		ms->playery = y;
		ms->playerview = 'N';
	}
	else if (c == 'S')
	{
		(ms->check)++;
		ms->playerx = x;
		ms->playery = y;
		ms->playerview = 'S';
	}
}

void	config_check(t_map_struct *ms)
{
	int	i;

	i = 0;
	while (ms->config[i])
	{
		if (ft_strnstr(ms->config[i], "NO ", 3))
			ms->north++;
		else if (ft_strnstr(ms->config[i], "SO ", 3))
			ms->south++;
		else if (ft_strnstr(ms->config[i], "WE ", 3))
			ms->west++;
		else if (ft_strnstr(ms->config[i], "EA ", 3))
			ms->east++;
		else if (ft_strnstr(ms->config[i], "F ", 2))
			ms->floor++;
		else if (ft_strnstr(ms->config[i], "C ", 2))
			ms->ceiling++;
		i++;
	}
	if (ms->north == 1 && ms->south == 1 && ms->east == 1 && ms->west == 1
		&&ms->floor == 1 && ms->ceiling == 1)
		return ;
	else
		error_and_msg("Wrong Config Info", 2);
}

static int	check_map(t_map_struct	*ms, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= ms->with || y >= ms->height)
		error_and_msg("Invalid map", 2);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (1);
	if (map[y][x] == ' ')
		error_and_msg("Invalid map", 2);
	map[y][x] = 'X';
	check_map(ms, map, x + 1, y);
	check_map(ms, map, x - 1, y);
	check_map(ms, map, x, y + 1);
	check_map(ms, map, x, y - 1);
	return (4);
}

void	flood_map(t_map_struct *ms)
{
	check_map(ms, ms->map, ms->playerx, ms->playery);
	ms->map[ms->height] = NULL;
}
