/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_less_itoa.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/09 17:27:30 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	reverse(long nbr)
{
	long	reverse;
	long	n_remain;

	reverse = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr)
	{
		n_remain = nbr % 10;
		reverse = reverse * 10 + n_remain;
		nbr = nbr / 10;
	}
	return (reverse);
}

static int	ft_convert(long nbr, char *str)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		str[0] = '0';
		i++;
	}
	nbr = reverse(nbr);
	while (nbr != 0)
	{
		str[i] = (nbr % 10) + 48;
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static int	ft_put_zero(char *str, int n, int i)
{
	int	check;

	check = 0;
	while (n % 10 == 0 && n != 0)
	{
		check++;
		n = n / 10;
	}
	while (check)
	{
		str[i] = '0';
		i++;
		check--;
	}
	return (i);
}

char	*ft_malloc_less_itoa(int n)
{
	static char	str[20];
	long		nbr;
	int			i;

	nbr = n;
	ft_memset(str, 0, 20);
	i = ft_convert(nbr, str);
	i = ft_put_zero(str, n, i);
	return (str);
}
