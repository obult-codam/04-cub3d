/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 17:31:22 by izaak         #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:59 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest1;
	char		*src1;

	dest1 = dest;
	src1 = (char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest1 > src1)
	{
		while (n)
		{
			n--;
			dest1[n] = src1[n];
		}
		return (dest1);
	}
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
