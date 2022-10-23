/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 15:06:05 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	reverse(long nbr, int fd)
{
	long	reverse;
	long	n_remain;

	reverse = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	while (nbr)
	{
		n_remain = nbr % 10;
		reverse = reverse * 10 + n_remain;
		nbr = nbr / 10;
	}
	return (reverse);
}

static void	ft_zero_print(int zero_count, int fd)
{
	while (zero_count)
	{
		ft_putchar_fd('0', fd);
		zero_count--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		zero_count;

	zero_count = 0;
	nbr = n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	while (nbr % 10 == 0)
	{
		zero_count++;
		nbr = nbr / 10;
	}
	nbr = reverse(nbr, fd);
	while (nbr)
	{
		ft_putchar_fd((nbr % 10) + '0', fd);
		nbr = nbr / 10;
	}
	ft_zero_print(zero_count, fd);
}
