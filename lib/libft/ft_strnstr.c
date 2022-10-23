/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 17:21:27 by izaak         #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:59 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str2[i] == 0)
		return ((char *)str1);
	while (str1[i] != '\0' && str2[j] != '\0' && i < n)
	{
		while (str1[i + j] == str2[j])
		{
			j++;
			if (str2[j] == '\0' && (i + j) <= n)
			{
				return ((char *)str1 + i);
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
