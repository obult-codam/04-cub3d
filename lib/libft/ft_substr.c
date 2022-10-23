/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Ivellinga <izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 16:08:00 by izaak         #+#    #+#                 */
/*   Updated: 2022/07/07 22:39:12 by Ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str1, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str2;

	str2 = ft_calloc(len + 1, sizeof(char));
	if (str2 == 0 || str1 == 0)
		return (NULL);
	j = 0;
	i = 0;
	if (start >= (unsigned int)ft_strlen((char *)str1))
		return (str2);
	while (i < start)
		i++;
	while (j <= len - 1 && len != 0)
	{
		str2[j] = str1[i];
		i++;
		j++;
	}
	return (str2);
}
