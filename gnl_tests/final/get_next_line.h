/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:27:31 by mchepil           #+#    #+#             */
/*   Updated: 2018/01/23 18:07:20 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 20
# define FD_MAX 4864

typedef struct		s_lst
{
	char	*st_line;
}					t_lst;

char	*ft_read_write_file(int fd);
t_lst	*add_list(t_lst *new);
int		get_next_line(const int fd, char **line);

#endif
