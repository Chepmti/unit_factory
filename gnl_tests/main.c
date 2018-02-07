/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:43:03 by mchepil           #+#    #+#             */
/*   Updated: 2018/01/11 12:43:09 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <assert.h>
#include <stdio.h>

 int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char 	*line;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	system ("leaks a.out");
/*	get_next_line(fd2, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);*/
	close(fd);
	return (0);
}

/*int		main(int argc, char **argv)
{
    char 	*line = NULL;
    
	assert(get_next_line(-99, NULL) == -1);
	assert(get_next_line(-1, NULL) == -1);
	assert(get_next_line(-10000, NULL) == -1);
	assert(get_next_line(1, NULL) == -1);
	assert(get_next_line(99, NULL) == -1);

	assert(get_next_line(-99, &line) == -1);
	assert(get_next_line(-1, &line) == -1);
	assert(get_next_line(-10000, &line) == -1);

	 Not opened fd 
	assert(get_next_line(42, &line) == -1);
}
*/