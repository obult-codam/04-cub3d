/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_print.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/18 17:51:12 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	width_print(t_struct *data, int conv_width)
{
	int	a;
	int	i;

	a = ' ';
	i = 0;
	if (conv_width > data->d_pre && data->d_pre > 0)
		data->d_width = data->d_width - data->d_pre;
	else
		data->d_width = data->d_width - conv_width;
	i = 0;
	if (data->d_zero > 0 && data->d_dash == 0)
		a = '0';
	while (i < data->d_width)
	{
		write(1, &a, sizeof(char));
		i++;
		data->printed++;
	}
}

int	width_int_print(t_struct *data, int conv_width, int check)
{
	int	a;
	int	i;

	a = ' ';
	i = 0;
	if (data->d_pre > conv_width)
		data->d_width = data->d_width - data->d_pre - data->check;
	else
	{
		data->d_width = data->d_width - conv_width - data->check;
	}
	if (data->d_zero > 0 && data->d_dash == 0 && data->d_pre <= 0)
		a = '0';
	if (check == 1 && a == '0' && data->d_width > 0)
	{
		data->printed += write(1, "-", 1);
		check = 0;
	}
	while (i < data->d_width)
	{
		write(1, &a, sizeof(char));
		i++;
		data->printed++;
	}
	return (check);
}
