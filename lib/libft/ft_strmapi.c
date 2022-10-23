/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 19:06:50 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str1;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	str1 = ft_calloc(ft_strlen((char *)str) + 1, 1);
	if (!str1)
		return (NULL);
	while (str[i])
	{
		str1[j] = (*f)(i, str[i]);
		i++;
		j++;
	}
	return (str1);
}
