/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hexidecimal.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/26 17:26:16 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	str_reverse(char *str, t_struct *data, int print)
{
	char				new[20];
	unsigned long		i;
	unsigned long		j;
	unsigned long		strlen;

	i = 0;
	j = ft_strlen(str) - 1;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		new[i] = str[j];
		i++;
		j--;
	}
	data->d_hexlen = ft_strlen(str);
	if (print)
		data->printed = data->printed + write(1, new, i);
}

static void	hextoa(t_struct *data, unsigned long n, int print)
{
	char	buff[20];
	int		i;
	int		rest;

	if (data->d_dot > 0 && data->d_width > data->d_pre && data->d_pre >= 0)
		data->d_zero = 0;
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

static void	print_null(t_struct *data)
{
	if (data->d_dash == 0)
	{
		width_int_print(data, 1, 0);
		data->printed += write(1, "0", 1);
	}
	else
	{
		data->printed += write(1, "0", 1);
		width_int_print(data, 1, 0);
	}
	return ;
}

void	convert_hexidecimal(t_struct *data, va_list va)
{
	long	nbr;

	nbr = va_arg(va, unsigned int);
	if (nbr == 0 && !data->d_dot && !data->d_pre)
	{
		print_null(data);
		return ;
	}
	hextoa(data, nbr, 0);
	if (data->d_dash == 0)
	{
		if (nbr == 0 && data->d_pre < 0 && !data->d_zero)
			data->d_width = data->d_width - 1;
		width_int_print(data, data->d_hexlen, 3);
		zero_print(data, data->d_hexlen, NO_MIN);
		hextoa(data, nbr, 1);
	}
	else if (data->d_dash > 0)
	{
		zero_print(data, data->d_hexlen, NO_MIN);
		hextoa(data, nbr, 1);
		width_int_print(data, data->d_hexlen, NO_MIN);
	}
}
