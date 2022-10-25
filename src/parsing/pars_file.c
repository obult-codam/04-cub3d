/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pars_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ieilat <ieilat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 19:22:36 by ieilat        #+#    #+#                 */
/*   Updated: 2022/10/25 17:52:38 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parsing.h"
#include "libft.h"
#include "utils.h"

void	check_map_values(char c, t_map_struct *ms, int x, int y)
{
	if (c == '0' || c == ' ' || c == '1')
		return ;
	if (c == 'N' || c == 'S')
		check_north_south(c, ms, x, y);
	else if (c == 'E')
	{
		(ms->check)++;
		ms->playerx = x;
		ms->playery = y;
		ms->playerview = 'E';
	}
	else if (c == 'W')
	{
		(ms->check)++;
		ms->playerx = x;
		ms->playery = y;
		ms->playerview = 'W';
	}
	else
		error_and_msg("Wrong Character", 2);
	if (ms->check > 1)
		error_and_msg("To many start positions", 2);
}

static	void	split_array(char ***arr, t_map_struct *ms)
{
	int	i;

	i = 0;
	ms->input = (*arr);
	if (arr_len(*arr) < 6)
		error_and_msg("Missing Config Info", 2);
	ms->config = ft_calloc(7, sizeof(char *));
	while (i < 6)
	{
		ms->config[i] = **arr;
		i++;
		(*arr)++;
	}
	config_check(ms);
}

static	void	fill_map(t_map_struct *ms)
{
	int	i;

	i = 0;
	ms->map = malloc((ms->height + 1) * sizeof(char *));
	if (ms->map == NULL)
		error_and_msg("Allocation Fail", 2);
	ms->map[ms->height - 1] = NULL;
	while (i < ms->height)
	{
		ms->map[i] = ft_calloc(ms->with + 1, sizeof(char));
		if (ms->map[i] == NULL)
			error_and_msg("Allocation Fail", 2);
		ft_memset(ms->map[i], ' ', ms->with - 1);
		i++;
	}
}

static	void	make_map_rectangular(t_map_struct *ms, char	**non_rec_map_arr)
{
	int	i;
	int	j;

	fill_map(ms);
	i = 0;
	while (ms->map[i] && non_rec_map_arr[i])
	{
			j = 0;
		while (non_rec_map_arr[i][j])
		{
			ms->map[i][j] = non_rec_map_arr[i][j];
			check_map_values(non_rec_map_arr[i][j], ms, j, i);
			j++;
		}
		i++;
	}
	if (ms->check == 0)
		error_and_msg("No start position", 2);
	flood_map(ms);
}

void	file_parser(t_map_struct *ms, int fd)
{
	int		ret;
	char	temp[10000];
	char	*mapstr;
	char	**non_rec_map_arr;

	ret = 1;
	mapstr = NULL;
	while (ret)
	{
		ret = read(fd, temp, 10000);
		if (ret == -1)
			error_and_msg("File Misconfig", 2);
		else if (ret == 0)
			break ;
		temp[ret] = '\0';
		mapstr = null_strjoin(mapstr, temp);
		if (mapstr == NULL)
			error_and_msg("Allocation Fail", 2);
	}
	non_rec_map_arr = split_mapstr(ms, mapstr, '\n');
	free(mapstr);
	if (non_rec_map_arr == NULL)
		error_and_msg("Allocation Fail", 2);
	split_array(&non_rec_map_arr, ms);
	make_map_rectangular(ms, non_rec_map_arr);
}
