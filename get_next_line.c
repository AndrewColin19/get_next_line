/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */

/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:24:18 by acolin            #+#    #+#             */
/*   Updated: 2021/10/22 14:32:03 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_buf(char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

int	check_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *buffer, char *save)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 1);
	ft_strlcpy(line, buffer, i + 2);
	ft_strlcpy(save, buffer + i + 1, ft_strlen(buffer));
	line[i + 1] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);	
	}
	return (line);
}

char	*cat_buf(char *dst, char *src)
{
	char	*tmp;
	size_t	tmp_size;

	tmp = dst;
	tmp_size = ft_strlen(tmp);
	ft_strlcpy(dst, tmp, (tmp_size + BUFFER_SIZE + 1));
	ft_strlcat(dst, src, (tmp_size + BUFFER_SIZE + 1));
	return (dst);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*buff_stock;
	static char	save[BUFFER_SIZE];

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE == 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buff_stock = save;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (buffer[0] == '\0')
			return (NULL);
		if(check_buffer(buffer, BUFFER_SIZE) == NULL)
			return (NULL);
		cat_buf(buff_stock, buffer);
		clear_buf(buffer, BUFFER_SIZE);
		if (check_line(buff_stock))
			break ;
	}
	free(buffer);
	return (get_line(buff_stock, save));
}
