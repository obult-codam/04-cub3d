/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaak <izaak@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 16:59:49 by izaak         #+#    #+#                 */
/*   Updated: 2022/01/17 21:19:59 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*gnl_calloc(size_t count, size_t size)
{
	size_t			n;
	char			*str;
	size_t			i;
	unsigned char	*unsigned_str;

	str = malloc(count * size);
	if (str == 0)
		return (NULL);
	n = count * size;
	i = 0;
	unsigned_str = (unsigned char *)str;
	while (i < n)
	{
		unsigned_str[i] = (unsigned char) 0;
		i++;
	}
	return (str);
}

char	*gnl_strjoin(char *buff, char *line)
{
	int		len;
	int		x;
	int		k;
	char	*str3;

	k = 0;
	x = 0;
	len = gnl_strlen(buff) + gnl_strlen(line);
	str3 = gnl_calloc(len + 1, sizeof(char));
	if (str3 == NULL)
		return (NULL);
	while (buff[k])
	{
		str3[k] = buff[k];
		k++;
	}
	free(buff);
	while (line[x])
	{
		str3[k] = line[x];
		k++;
		x++;
	}
	free((line));
	return (str3);
}

int	gnl_free_all(char **buff, char **line, int fd)
{
	if (buff[fd] != NULL)
	{
		free(buff[fd]);
	}
	*buff = NULL;
	if (line != NULL)
	{
		free((*line));
	}
	*line = NULL;
	return (-1);
}

int	final_line(char *buff, int newline_index, char **line)
{
	int		i;
	char	*temp;

	temp = gnl_calloc(newline_index + 1, sizeof(char));
	if (temp == NULL)
	{
		*line = NULL;
		return (-1);
	}
	i = 0;
	while (i < newline_index)
	{
		temp[i] = buff[i];
		i++;
	}
	*line = temp;
	return (1);
}
