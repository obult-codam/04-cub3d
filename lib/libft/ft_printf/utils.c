/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 19:53:15 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:00 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	zero_print(t_struct *data, int conversion, int check)
{
	int	nbr;
	int	i;
	int	width_pos;

	width_pos = 1;
	i = 0;
	if (data->negative_w > 0 || !data->d_width)
		width_pos = 0;
	if (conversion == 0 && data->d_pre < 0 && (!data->d_zero || !width_pos))
	{
		data->printed += write(1, "0", 1);
		data->d_width = data->d_width - 1;
	}
	nbr = data->d_pre - conversion;
	if (check == 1)
		data->printed += write(1, "-", 1);
	while (i < nbr)
	{
		data->printed += write(1, "0", 1);
		i++;
	}
}
