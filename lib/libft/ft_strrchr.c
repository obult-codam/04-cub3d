/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 16:54:50 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*copy;
	int			i;

	i = 0;
	copy = str;
	while (*str)
	{
		str++;
		i++;
	}
	while (*str >= 0 && str != copy - 1)
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		if (i > 0)
		{
			str--;
			i--;
		}
		else
			return (NULL);
	}
	return (NULL);
}
