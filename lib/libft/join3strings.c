/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   join3strings.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 22:52:01 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/26 19:10:27 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_3_strings(const char *str0, const char *str1, const char *str2)
{
	int		len0;
	int		len2;
	char	*str3;

	len0 = ft_strlen(str0);
	len2 = ft_strlen(str2);
	str3 = ft_calloc(len0 + 1 + len2 + 1, sizeof(char));
	if (str3 == NULL)
		return (NULL);
	ft_memmove(str3, str0, len0);
	ft_memmove(str3 + len0, str1, 1);
	ft_memmove(str3 + len0 + 1, str2, len2);
	return (str3);
}
