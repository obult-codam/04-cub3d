/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 18:14:21 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_substr_start(const char *str1, const char *set, int len)
{
	int	i;

	i = 0;
	while (str1[i] && ft_strchr(set, str1[i]))
	{
		i++;
		if (i == len)
			return (0);
	}
	return (i);
}

static int	get_substr_end(const char *str1, const char *set, int len)
{
	int	i;

	i = len - 1;
	while (str1[i] && ft_strchr(set, str1[i]))
	{
		i--;
		if (i == -1)
			return (0);
	}
	return (i);
}

static char	*ft_make_substr(const char *s1, int i, int j, int len)
{
	int		k;
	char	*substr;

	substr = ft_calloc(j - i + 2, sizeof(char));
	if (substr == 0)
		return (NULL);
	k = 0;
	if (j == 0 && i == 0)
		len = 0;
	while (i <= j && k != len)
	{
		substr[k] = s1[i];
		i++;
		k++;
	}
	return (substr);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*substr;
	int		substr_start;
	int		substr_end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen((char *)s1);
	substr_start = get_substr_start(s1, set, len);
	substr_end = get_substr_end(s1, set, len);
	substr = ft_make_substr(s1, substr_start, substr_end, len);
	return (substr);
}
