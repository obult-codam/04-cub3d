/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 14:54:15 by izaak         #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:59 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

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

static char	*ft_convert(int n, char *str)
{
	long	nbr;

	nbr = n;
	if (nbr == 0)
	{
		*str = '0';
		str++;
	}
	if (nbr < 0)
	{
		*str = '-';
		str++;
	}
	nbr = reverse(nbr);
	while (nbr != 0)
	{
		*str = (nbr % 10) + 48;
		str++;
		nbr = nbr / 10;
	}
	return (str);
}

static char	*ft_put_zero(char *str, int n)
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
		*str = '0';
		str++;
		check--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		len;

	nbr = n;
	str = ft_calloc(ft_nbrlen(nbr) + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = ft_convert(nbr, str);
	len = ft_nbrlen(nbr);
	str = ft_put_zero(str, n);
	while (len > 0)
	{
		len--;
		str--;
	}
	return (str);
}
