/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uns_itoa.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 14:54:15 by izaak         #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:59 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	reverse(unsigned int nbr)
{
	unsigned long	reverse;
	unsigned long	n_remain;

	reverse = 0;
	while (nbr)
	{
		n_remain = nbr % 10;
		reverse = reverse * 10 + n_remain;
		nbr = nbr / 10;
	}
	return (reverse);
}

static int	ft_convert(unsigned long nbr, char *str)
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

static int	ft_put_zero(char *str, unsigned int n, int i)
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

char	*ft_uns_itoa(unsigned int n)
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
