/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extention_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 22:02:48 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/19 12:14:49 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	extention_check(char *str, char *ext)
{
	int		dif;

	dif = ft_strlen(str) - ft_strlen(ext);
	if (dif < 0)
		return (2);
	str += dif;
	if (ft_strnstr(str, ext, ft_strlen(ext)))
		return (0);
	return (1);
}
