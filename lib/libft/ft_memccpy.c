/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:31:05 by izaak         #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:59 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	const char		*src1;

	i = 0;
	dest1 = (unsigned char *)dest;
	src1 = (const char *)src;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
		if (dest1[i - 1] == (unsigned char)c)
		{
			return (dest1 + i);
		}
	}
	return (NULL);
}
