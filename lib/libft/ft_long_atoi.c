/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_long_atoi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 21:43:48 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_long_atoi(long *out, const char *str)
{
	int		i;
	long	scale;
	long	print;

	print = 0;
	scale = 1;
	i = 0;
	if ((str[0] == '-' && !ft_isdigit(str[1])) || str[0] == 0)
		return (1);
	if (str[i] == '-')
	{
		scale = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		print = print * 10 + str[i] - '0';
		i++;
		if ((scale * print) > MAX_INT || (scale * print) < MAX_MIN_INT)
			return (1);
	}
	*out = scale * print;
	return (0);
}
