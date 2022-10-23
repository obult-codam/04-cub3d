/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_2d_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 21:38:02 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/01/24 21:38:24 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("{%d} = %s\n", i, arr[i]);
		i++;
	}
}
