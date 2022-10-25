/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ieilat <ieilat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:14:35 by ieilat        #+#    #+#                 */
/*   Updated: 2022/10/25 17:21:42 by ieilat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdio.h>

static int	rgb_atoi(char *str, char **outstr, long *res)
{
	int		i;
	long	scale;
	long	print;

	print = 0;
	scale = 1;
	i = 0;
	if (str[i] == '-')
	{
		scale = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			break ;
		print = print * 10 + str[i] - '0';
		i++;
		if ((scale * print) > MAX_INT || (scale * print) < MAX_MIN_INT)
			return (1);
	}
	*res = scale * print;
	*outstr += i;
	return (0);
}

static	unsigned int	set_color(char *str)
{
	char	*outstr;
	long	res;
	int		arr[3];
	int		i;

	outstr = str + 1;
	i = 0;
	while (i < 3)
	{
		if (ft_isdigit(*outstr))
		{
			rgb_atoi(outstr, &outstr, &res);
			arr[i++] = res;
		}
		else if (*outstr == ' ' || *outstr == ',')
			outstr++;
		else
			error_and_msg("Wrong Color input", 2);
	}
	if (*outstr != '\0')
		error_and_msg("Wrong Color input", 2);
	return (arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | 0xff);
}

static	char	*skip_spaces(char *str)
{
	char	*temp;
	int		i;

	temp = str + 2;
	i = 0;
	while (*temp == ' ')
		temp++;
	return (temp);
}

static	void	set_texture(char *str, t_map_struct *ms)
{
	int	i;

	i = 0;
	if (ft_strnstr(str, "NO ", 3))
		ms->textures[0] = mlx_load_png(skip_spaces(str));
	else if (ft_strnstr(str, "SO ", 3))
		ms->textures[1] = mlx_load_png(skip_spaces(str));
	else if (ft_strnstr(str, "WE ", 3))
		ms->textures[2] = mlx_load_png(skip_spaces(str));
	else if (ft_strnstr(str, "EA ", 3))
		ms->textures[3] = mlx_load_png(skip_spaces(str));
	else if (ft_strnstr(str, "F ", 2))
		ms->floor = set_color(str);
	else if (ft_strnstr(str, "C ", 2))
		ms->ceiling = set_color(str);
}

void	init_textures(t_map_struct *ms)
{
	int	i;

	i = 0;
	while (ms->config[i])
	{
		set_texture(ms->config[i], ms);
		i++;
	}
	i = 0;
	while (i < 4)
	{	
		if (!ms->textures[i])
			error_and_msg("Textures missing or Wrong", 2);
		i++;
	}
	printf("F = %lx\nC = %lx\n", ms->floor, ms->ceiling);
}
