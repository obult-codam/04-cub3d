/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 18:30:59 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h" 

void	parse_all(const char *str, t_struct *data, va_list va)
{
	data->i++;
	flags(str, data);
	width(str, data, va);
	precision(str, data, va);
	conversion(str, data, va);
}

void	flags(const char *str, t_struct *data)
{
	while (str[data->i])
	{
		if (str[data->i] == '-')
			data->d_dash++;
		else if (str[data->i] == '0')
			data->d_zero++;
		else
			break ;
		data->i++;
	}
}

void	width(const char *str, t_struct *data, va_list va)
{
	while (ft_isdigit(str[data->i]))
	{
		data->d_width = data->d_width * 10 + str[data->i] - '0';
		data->i++;
	}
	if (str[data->i] == '*')
	{
		data->d_width = va_arg(va, int);
		if (data->d_width < 0)
		{
			data->d_width = data->d_width * -1;
			data->d_dash++;
			data->negative_w++;
		}
		data->i++;
	}
}

void	precision(const char *str, t_struct *data, va_list va)
{
	if (str[data->i] == '.')
	{
		data->d_dot++;
		data->i++;
	}
	while (ft_isdigit(str[data->i]))
	{
		data->d_pre = data->d_pre * 10 + str[data->i] - '0';
		data->i++;
	}
	if (str[data->i] == '*')
	{
		data->d_pre = va_arg(va, int);
		if (data->d_pre < 0)
			data->negative_p++;
		data->i++;
	}
}

void	conversion(const char *str1, t_struct *data, va_list va)
{
	static t_printfunct	arr[128];
	unsigned char		*str;

	str = (unsigned char *)str1;
	arr['c'] = convert_char;
	arr['s'] = convert_string;
	arr['d'] = convert_int;
	arr['i'] = convert_int;
	arr['u'] = convert_uns_int;
	arr['p'] = convert_pointer;
	arr['x'] = convert_hexidecimal;
	arr['X'] = convert_hexidecimal;
	arr['%'] = convert_percent;
	if (str[data->i] == 'X')
		data->xcheck = 55;
	if (arr[str[data->i]])
		arr[str[data->i]](data, va);
}
