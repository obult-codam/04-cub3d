/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   null_strjoin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ieilat <ieilat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:16:52 by ieilat        #+#    #+#                 */
/*   Updated: 2022/10/04 21:16:19 by ieilat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdlib.h>

char	*null_strjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	int		len3;
	char	*str3;

	len1 = 0;
	if (str1)
		len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	len3 = len1 + len2;
	str3 = ft_calloc(len3 + 1, sizeof(char));
	if (str3 == NULL)
	{
		free(str1);
		return (str3);
	}
	ft_memmove(str3, str1, len1);
	free(str1);
	ft_memmove(str3 + len1, str2, len2);
	return (str3);
}
