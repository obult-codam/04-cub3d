/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 15:31:57 by izaak         #+#    #+#                 */
/*   Updated: 2022/09/05 19:53:01 by ivelling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

static char	*ft_make_str(char c, const char *str)
{
	int		i;
	char	*rtrn;
	int		len;

	i = 0;
	len = ft_wrdlen(str, c);
	rtrn = malloc(len * sizeof(char) + 1);
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

static void	*ft_free_string(char **chr_arr, int i)
{
	while (i > 0)
	{
		i--;
		free(chr_arr[i]);
	}
	free(chr_arr);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	char	**chr_arr;

	if (!str)
		return (NULL);
	i = 0;
	chr_arr = ft_calloc(ft_wrd_cnt(str, c), sizeof(char *));
	if (!chr_arr)
		return (NULL);
	while (ft_wrd_cnt(str, c) > 1)
	{
		while (*str == c)
			str++;
		chr_arr[i] = ft_make_str(c, str);
		if (chr_arr[i] == 0)
			return (ft_free_string(chr_arr, i));
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
	return (chr_arr);
}
