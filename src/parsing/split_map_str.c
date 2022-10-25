/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_map_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ieilat <ieilat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:08:49 by ieilat        #+#    #+#                 */
/*   Updated: 2022/10/25 17:28:14 by ieilat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>

static int	ft_wrd_cnt(const char *str, char c)
{
	int		i;
	int		word_count;

	i = 0;
	word_count = 1;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			while (str[i] != c && str[i])
			{
				i++;
			}
			word_count++;
		}
	}
	return (word_count);
}

static int	ft_wrdlen(const char *str, char c)
{
	int	word_len;

	word_len = 0;
	while (*str == c)
		str++;
	while (*str != c && *str != 0)
	{
		str++;
		word_len++;
	}
	return (word_len);
}

static char	*ft_make_str(t_map_struct *ms, const char *str, const char c)
{
	int		i;
	char	*rtrn;
	int		len;

	i = 0;
	len = ft_wrdlen(str, c);
	if (len > ms->with)
		ms->with = len;
	rtrn = malloc((len + 1) * sizeof(char));
	if (rtrn == 0)
		return (NULL);
	while (*str != c)
	{
		rtrn[i] = *str;
		i++;
		str++;
		if (i == len)
		{
			rtrn[i] = 0;
			return (rtrn);
		}
	}
	rtrn[i] = 0;
	return (rtrn);
}

static void	*ft_free_string(char **chr_arr, int i, int check)
{
	while (i > 0)
	{
		i--;
		free(chr_arr[i]);
	}
	free(chr_arr);
	if (check == 0)
		error_and_msg("Invalid map", 2);
	return (NULL);
}

char	**split_mapstr(t_map_struct *ms, const char *str, char c)
{
	int		i;
	char	**chr_arr;

	if (!str)
		return (NULL);
	i = 0;
	chr_arr = ft_calloc(ft_wrd_cnt(str, c) + 1, sizeof(char *));
	ms->height = ft_wrd_cnt(str, c) + 1;
	if (!chr_arr)
		return (NULL);
	while (ft_wrd_cnt(str, c) > 1)
	{
		while (*str == c)
			str++;
		chr_arr[i] = ft_make_str(ms, str, c);
		if (chr_arr[i] == 0)
			return (ft_free_string(chr_arr, i, 1));
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
	return (chr_arr);
}
