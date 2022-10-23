/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_pointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 17:14:23 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	str_reverse(char *str, t_struct *data, int print)
{
	char				new[20];
	int					i;
	int					j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < ft_strlen(str))
	{
		new[i] = str[j];
		i++;
		j--;
	}
	if (ft_strlen(str) != 0)
		data->d_hexlen = ft_strlen(str);
	if (print)
	{
		data->printed = data->printed + write(1, "0", 1);
		data->printed = data->printed + write(1, "x", 1);
		data->printed = data->printed + write(1, new, i);
	}
}

static void	long_hextoa(t_struct *data, uint64_t n, int print)
{
	char			buff[20];
	int				i;
	uint64_t		rest;

	data->d_hexlen = 2;
	rest = 0;
	i = 0;
	while (n != 0)
	{
		rest = n % 16;
		if (rest < 10)
		{
			buff[i] = rest + 48;
			i++;
		}
		else
		{
			buff[i] = rest + data->xcheck;
			i++;
		}
		n = n / 16;
	}
	buff[i] = '\0';
	str_reverse(buff, data, print);
}

void	convert_pointer(t_struct *data, va_list va)
{
	uint64_t	nbr;

	data->check = 2;
	nbr = va_arg(va, uint64_t);
	long_hextoa(data, nbr, 0);
	if (nbr == 0 && data->d_dot > 0)
		data->check = 0;
	if (nbr == 0 && data->d_width > 0 && data->d_dot == 0)
		data->check = 1;
	if (data->d_dash == 0)
	{
		width_int_print(data, data->d_hexlen, data->check);
		zero_print(data, data->d_hexlen, NO_MIN);
		long_hextoa(data, nbr, 1);
		if (nbr == 0 && data->d_dot == 0)
			data->printed = data->printed + write(1, "0", 1);
	}
	else if (data->d_dash > 0)
	{
		zero_print(data, data->d_hexlen, NO_MIN);
		long_hextoa(data, nbr, 1);
		if (nbr == 0 && data->d_dot == 0)
			data->printed = data->printed + write(1, "0", 1);
		width_int_print(data, data->d_hexlen, data->check);
	}
}
