/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:24:18 by acolin            #+#    #+#             */
/*   Updated: 2021/10/20 17:47:19 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next(char **buffer_s)
{
	int		i;
	char	*buf_tmp;
	char 	*ret;

	buf_tmp = NULL;
	i = 0;
	while (buffer_s[0][i] != '\n' && buffer_s[0][i] != '\0')
		i++;
	buf_tmp = ft_strdup(buffer_s[0], ft_strlen(buffer_s[0]));
	free(buffer_s[0]);
	ft_strlcat(buffer_s[0], buf_tmp + i + 1, ft_strlen(buf_tmp + i));
	ret = ft_strdup(buf_tmp , i);
	if (ft_strlen(ret) == 0)
		free(ret);
	buf_tmp = ft_strdup(buf_tmp + i + 1, ft_strlen(buf_tmp + i));
	buffer_s[0] = ft_strdup(buf_tmp, ft_strlen(buf_tmp));
	free(buf_tmp);
	return (ret);
}

char	*get_line(char *buffer, char **buffer_s)
{
	int		i;
	char	*buf_tmp;

	i = 0;
	buf_tmp = NULL;
	while (buffer_s[0][i] != '\n')
		i++;
	buf_tmp = ft_strdup(buffer_s[0], ft_strlen(buffer_s[0]));
	free(buffer_s[0]);
	buffer = malloc(sizeof(char) * i + 2);
	buffer_s[0] = malloc(sizeof(char) * ft_strlen(buf_tmp) - i + 1);
	ft_strlcpy(buffer, buf_tmp, i + 1);
	ft_strlcpy(buffer_s[0], (buf_tmp + i + 1), ft_strlen(buf_tmp) - i);
	free(buf_tmp);
	return (buffer);
}

void	swap_buf(char *buffer, char **buffer_s)
{
	char	*buf_tmp;

	buf_tmp = NULL;
	if (*buffer_s)
	{
		buf_tmp = ft_strdup(*buffer_s, ft_strlen(buffer_s[0]));
		free(*buffer_s);
		*buffer_s = malloc(ft_strlen(buf_tmp) + BUFFER_SIZE + 2);
		ft_strlcpy(*buffer_s, buf_tmp, ft_strlen(buf_tmp));
		free(buf_tmp);
		ft_strlcat(*buffer_s, buffer, ft_strlen(*buffer_s) + BUFFER_SIZE + 2);
	}
	else
	{
		*buffer_s = malloc(BUFFER_SIZE + 2);
		ft_strlcat(*buffer_s, buffer, BUFFER_SIZE + 2);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer_s;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		swap_buf(buffer, &buffer_s);
		return (get_line(buffer, &buffer_s));
	}
	return (next(&buffer_s));
}
