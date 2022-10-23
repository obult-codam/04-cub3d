/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 15:42:18 by izaak         #+#    #+#                 */
/*   Updated: 2022/08/11 20:44:07 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	int		len3;
	char	*str3;

	len1 = 0;
	if (str1)
		len1 = ft_strlen(str1);
	len2 = 0;
	if (str2)
		len2 = ft_strlen(str2);
	len3 = len1 + len2;
	str3 = ft_calloc(len3 + 1, sizeof(char));
	if (str3 == NULL)
	{
		free(str1);
		free(str2);
		return (str3);
	}
	ft_memmove(str3, str1, len1);
	free(str1);
	ft_memmove(str3 + len1, str2, len2);
	free(str2);
	return (str3);
}
