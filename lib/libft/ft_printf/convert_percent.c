/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_percent.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/29 16:50:11 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	convert_percent(t_struct *data, va_list va)
{
	char	character;

	character = '%';
	va = va - 0;
	if (data->d_dash == 0)
	{
		width_print(data, 1);
		data->printed += write(1, &character, sizeof(char));
	}
	else if (data->d_dash > 0)
	{
		data->printed += write(1, &character, sizeof(char));
		width_print(data, 1);
	}
}
