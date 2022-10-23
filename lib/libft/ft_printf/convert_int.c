/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 14:12:21 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	null_print(t_struct *data, long nbr)
{
	if (nbr == 0 && data->d_dot > 0 && !data->d_pre)
	{
		data->d_dash++;
		width_int_print(data, 0, 0);
		return (1);
	}
	return (0);
}

void	convert_int(t_struct *data, va_list va)
{
	long	nbr;
	char	*num;

	nbr = va_arg(va, int);
	if (null_print(data, nbr) == 1)
		return ;
	if (nbr < 0)
		data->check = 1;
	num = ft_malloc_less_itoa(nbr);
	if (data->d_dash == 0)
	{
		if (data->d_dot > 0 && !data->negative_p)
			data->d_dash++;
		data->check = width_int_print(data, ft_strlen(num), data->check);
		zero_print(data, ft_strlen(num), data->check);
		data->printed += write(1, num, ft_strlen(num));
	}
	else if (data->d_dash > 0)
	{
		zero_print(data, ft_strlen(num), data->check);
		data->printed += write(1, num, ft_strlen(num));
		width_int_print(data, ft_strlen(num), data->check);
	}
}
