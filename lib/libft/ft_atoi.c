/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 18:52:28 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int i)
{
	if (i == ' ' || i == '\t' || i == '\n' || i == '\v' || i == '\f')
	{
		return (1);
	}
	if (i == '\r' || i == '+' || i == '-')
		return (1);
	return (0);
}

static int	ft_pm(const char *str, int i)
{
	int	pmcount;

	pmcount = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
		{
			pmcount = 1;
		}
		pmcount++;
		i++;
	}
	return (pmcount);
}

static int	isdgit(int c)
{
	if (c > 47 && c < 58)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	scale;
	int	print;

	print = 0;
	scale = 1;
	i = 0;
	while (isdgit(str[i]) || ft_check(str[i]))
	{
		if (str[i] == '-')
			scale = -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				print = print * 10 + str[i] - '0';
				i++;
			}
			return (scale * print);
		}
		if (ft_pm(str, i) > 1)
			return (0);
		i++;
	}
	return (scale * print);
}
