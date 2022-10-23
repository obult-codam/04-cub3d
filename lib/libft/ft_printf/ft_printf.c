/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 17:50:48 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h" 

int	ft_printf(const char *str, ...)
{
	va_list				va;
	t_struct			data;

	init_struct(&data);
	va_start(va, str);
	while (str[data.i])
	{
		if (str[data.i] == '%')
		{
			parse_all(str, &data, va);
			reset_struct(&data);
		}
		else
			data.printed += write(1, &str[data.i], sizeof(char));
		data.i++;
	}
	va_end(va);
	return (data.printed);
}
