/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 13:07:37 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	dest_len;
	size_t	const_dstlen;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen(dest);
	const_dstlen = dest_len;
	if ((size_t)src > dst_size - const_dstlen - 1 || src == 0)
	{
		while (src[i] != '\0' && i < dst_size - const_dstlen - 1)
		{
			dest[dest_len] = src[i];
			dest_len++;
			i++;
		}
		dest[dest_len] = '\0';
	}
	if (const_dstlen > dst_size)
		return (src_len + dst_size);
	return (const_dstlen + src_len);
}
