/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 17:48:54 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_null(t_struct *data)
{
	if (data->d_dot > 0 && data->d_pre == 0)
	{
		width_print(data, 0);
		return ;
	}
	if (data->d_pre == 0 || 6 < data->d_pre || data->d_pre < 0)
		data->d_pre = 6;
	if (data->d_dash == 0)
	{
		width_print(data, 6);
		data->printed += write(1, "(null)", data->d_pre);
	}
	else if (data->d_dash > 0)
	{
		data->printed += write(1, "(null)", data->d_pre);
		width_print(data, 6);
	}
}

void	convert_string(t_struct *data, va_list va)
{
	char	*ptr;

	ptr = va_arg(va, char *);
	if (!ptr)
	{
		print_null(data);
		return ;
	}
	if (data->d_dot > 0 && data->d_pre == 0)
	{
		width_print(data, 0);
		return ;
	}
	if (data->d_pre == 0 || ft_strlen(ptr) < data->d_pre || data->d_pre < 0)
		data->d_pre = ft_strlen(ptr);
	if (data->d_dash == 0)
	{
		width_print(data, ft_strlen(ptr));
		data->printed += write(1, ptr, data->d_pre);
	}
	else if (data->d_dash > 0)
	{
		data->printed += write(1, ptr, data->d_pre);
		width_print(data, ft_strlen(ptr));
	}
}
