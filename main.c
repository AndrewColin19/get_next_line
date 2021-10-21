/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:56:15 by acolin            #+#    #+#             */
/*   Updated: 2021/10/21 18:38:21 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2)
{
	unsigned char	*sa;
	unsigned char	*sb;
	size_t			i;

	sa = (unsigned char *) s1;
	sb = (unsigned char *) s2;
	i = 0;
	while (sa[i] == sb[i] && sa[i] != '\0' && sb[i] != '\0')
		i++;
	return (sa[i] - sb[i]);
}

int	main(void)
{
	int	fd;

	fd = open("gnlTester/files/41_with_nl", O_RDONLY);
	printf("main = %s", get_next_line(fd)); 
	printf("main = %s", get_next_line(fd));
	printf("main = %s", get_next_line(fd));
	return (1);
}
