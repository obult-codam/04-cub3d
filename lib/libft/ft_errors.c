/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_errors.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 20:56:31 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/08/31 22:38:02 by ivelling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	error(int fd)
{
	write(fd, "Error\n", 6);
	write(fd, "\n", 1);
	exit(EXIT_FAILURE);
}

void	error_and_msg(const char *str, int fd)
{
	write(fd, "Error\n", 6);
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	exit(EXIT_FAILURE);
}

void	exit_msg(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	exit(EXIT_FAILURE);
}

void	double_exit_msg(const char *str, const char *str1, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, str1, ft_strlen(str1));
	write(fd, "\n", 1);
	exit(EXIT_FAILURE);
}

void	my_perror_exit(char *progname, const char *arg, int fd)
{
	char	*error;

	error = strerror(errno);
	write(fd, progname, ft_strlen(progname));
	write(fd, ": ", 2);
	write(fd, error, ft_strlen(error));
	write(fd, ": ", 2);
	write(fd, arg, ft_strlen(arg));
	write(fd, "\n", 1);
	exit(errno);
}
