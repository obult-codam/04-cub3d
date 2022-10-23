/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 17:11:44 by izaak         #+#    #+#                 */
/*   Updated: 2022/09/22 21:31:47 by ivelling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == 0 && *str == c)
	{
		return ((char *)str);
	}
	return (NULL);
}
