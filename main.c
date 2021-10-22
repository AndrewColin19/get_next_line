/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:56:15 by acolin            #+#    #+#             */
/*   Updated: 2021/10/22 14:03:29 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	fd;

	fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
	if (!strcmp(get_next_line(fd),"01234567890123456789012345678901234567890\n"))
		printf("ok\n");
	else
		printf("ko\n");
	if (!strcmp(get_next_line(fd),"987654321098765432109876543210987654321098\n"))
		printf("ok\n");
	else
		printf("ko\n");
	if (!strcmp(get_next_line(fd),"0123456789012345678901234567890123456789012\n"))
		printf("ok\n");
	else
		printf("ko\n");
	if (!strcmp(get_next_line(fd),"987654321098765432109876543210987654321098\n"))
		printf("ok\n");
	else
		printf("ko\n");
	if (!strcmp(get_next_line(fd),"01234567890123456789012345678901234567890"))
		printf("ok\n");
	else
		printf("ko\n");
	if (get_next_line(fd) == NULL)
		printf("ok\n");
	else
		printf("ko\n");
	return (1);
}
