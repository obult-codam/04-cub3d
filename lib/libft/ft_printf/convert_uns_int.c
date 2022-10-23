/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_uns_int.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 15:57:33 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	null_print(t_struct *data, unsigned int nbr)
{
	if (nbr == 0 && data->d_dot > 0 && !data->d_pre)
	{
		if (data->d_dot > 0 && data->d_width > data->d_pre && data->d_pre >= 0)
			data->d_zero = 0;
		width_int_print(data, 0, 0);
		return (1);
	}
	return (0);
}

void	convert_uns_int(t_struct *data, va_list va)
{
	unsigned int	nbr;
	char			*num;

	nbr = va_arg(va, unsigned int);
	if (null_print(data, nbr) == 1)
		return ;
	num = ft_uns_itoa(nbr);
	if (data->d_dot > 0 && data->d_width > data->d_pre && data->d_pre >= 0)
		data->d_zero = 0;
	if (data->d_dash == 0)
	{
		width_int_print(data, ft_strlen(num), 0);
		zero_print(data, ft_strlen(num), 0);
		data->printed += write(1, num, ft_strlen(num));
	}
	else if (data->d_dash > 0)
	{
		zero_print(data, ft_strlen(num), 0);
		data->printed += write(1, num, ft_strlen(num));
		width_int_print(data, ft_strlen(num), 0);
	}
}
