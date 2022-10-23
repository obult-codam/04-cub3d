/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 13:48:12 by izaak         #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:59 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	buff_order(char *buff, int newline_index)
{
	int		i;
	int		new_buff_start;
	int		buff_len;

	buff_len = gnl_strlen(buff);
	i = 0;
	new_buff_start = gnl_strlen(buff) - newline_index;
	newline_index = newline_index + 1;
	while (i < new_buff_start)
	{
		buff[i] = buff[newline_index];
		newline_index++;
		i++;
	}
	while (i <= buff_len)
	{
		buff[i] = (unsigned char) 0;
		i++;
	}
}

int	final_line_and_buff_order(char **buff2, int i, int the_end)
{
	int		j;
	char	*buff;

	j = 1;
	buff = *buff2;
	if (gnl_strlen(buff) == 0 || buff[i] != '\n')
		j = 0;
	buff_order((buff), i);
	if (the_end == 0 && (gnl_strlen((buff)) == 0 && j == 0))
	{
		free(buff);
		*buff2 = NULL;
		return (0);
	}
	return (1);
}

int	if_and_else(int fd, char **line, char **buff, int the_end)
{
	char	*temp;

	temp = buff[fd];
	if (the_end == -1)
	{
		return (gnl_free_all (buff, line, fd));
	}
	if (buff[fd] == NULL)
		buff[fd] = (*line);
	else
		buff[fd] = gnl_strjoin(buff[fd], *line);
	if (buff[fd] == NULL)
	{
		free(temp);
		return (gnl_free_all (buff, line, fd));
	}
	return (1);
}

int	gnl_main_part(char **line, int fd, int i, int the_end)
{
	static char	*buff[MAX_FD];

	if (!buff[fd])
		buff[fd] = gnl_calloc(1, sizeof(char *));
	if (!buff[fd])
		return (gnl_free_all(buff, line, fd));
	while (i == 0 || buff[fd][i] != '\n')
	{
		*line = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		the_end = read(fd, (*line), BUFFER_SIZE);
		if (if_and_else(fd, line, buff, the_end) == -1)
			return (-1);
		while (buff[fd][i] != '\0' || the_end == 0)
		{
			if (buff[fd][i] == '\n' || (buff[fd][i] == '\0' && the_end == 0))
			{
				if (final_line(buff[fd], i, line) == -1)
					return (-1);
				return (final_line_and_buff_order(&buff[fd], i, the_end));
			}
			i++;
		}
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int	i;
	int	the_end;

	the_end = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL || fd > MAX_FD)
		return (-1);
	i = 0;
	return (gnl_main_part(line, fd, i, the_end));
}
