/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:28:06 by mchepil           #+#    #+#             */
/*   Updated: 2017/12/20 15:28:47 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"


int		main(int argc,char **argv)
{
	int			fd;
	//int		read_from_file;
	//char		buffer;
	char		*file;
	//int		i;
	t_xy		*go;
	int 		j;

	j = 0;
	if (argc != 2)
		{
			ft_putstr("usage ./fillit [input file]");
			ft_putchar('\n');
			return (0);
		}
		
		fd = open(argv[1], O_RDONLY);
		file = read_write(fd);

		if (!valid_finish(file))
		{
			ft_putstr("Error");
			ft_putchar('\n');
			return (0);
		}
		close(fd);
	go = memory_for_blocks(file);
	result(file, go);
	return (0);
}
