/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 15:05:00 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_struct(t_struct *data)
{
	data->i = 0;
	data->d_dash = 0;
	data->d_zero = 0;
	data->d_star = 0;
	data->d_width = 0;
	data->d_dot = 0;
	data->d_pre = 0;
	data->d_hexlen = 0;
	data->xcheck = 87;
	data->printed = 0;
	data->check = 0;
	data->negative_w = 0;
	data->negative_p = 0;
}

void	reset_struct(t_struct *data)
{
	data->d_dash = 0;
	data->d_zero = 0;
	data->d_star = 0;
	data->d_width = 0;
	data->d_dot = 0;
	data->d_pre = 0;
	data->d_hexlen = 0;
	data->xcheck = 87;
	data->check = 0;
	data->negative_w = 0;
	data->negative_p = 0;
}
