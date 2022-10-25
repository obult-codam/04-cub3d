/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_2d_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 21:38:02 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/10/25 12:08:32 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	print_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("{%d} = %s\n", i, arr[i]);
		i++;
	}
}
