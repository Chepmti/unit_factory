/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:43 by mchepil           #+#    #+#             */
/*   Updated: 2018/01/23 18:02:48 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_read_write_file(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*file;
	int		j;
	char	*tmp;

	file = NULL;
	while ((j = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[j] = '\0';
		if (!file)
			file = ft_strdup(buf);
		else if (file)
		{
			tmp = ft_strdup(file);
			free(file);
			file = ft_strjoin(tmp, buf);
			free(tmp);
		}
	}
	return (file);
}*/

t_lst	*add_list(t_lst *new)
{
	new = (t_lst *)malloc(sizeof(t_lst));
	new->st_line = NULL;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	char			*chr;
	char			buf[BUFF_SIZE + 1];
	int				j;
	char	*file;
	char	*tmp;
	static t_lst	*new_line[FD_MAX];

	i = 0;
	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || fd >= FD_MAX || read(fd, new_line[fd], 0) < 0)
		return (-1);
	file = NULL;
	while ((j = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[j] = '\0';
		if (!file)
			file = ft_strdup(buf);
		else if (file)
		{
			tmp = ft_strdup(file);
			free(file);
			file = ft_strjoin(tmp, buf);
			free(tmp);
		}
	}
 	if(!new_line[fd])
 	{
 		new_line[fd] = add_list(new_line[fd]);
 		new_line[fd]->st_line = file;
 	}
 	chr = ft_strchr(new_line[fd]->st_line, '\n');
 	if (chr == NULL && ft_strlen((new_line[fd]->st_line)) > 0)
	{
		*line = ft_strdup((new_line[fd]->st_line));
		*(new_line[fd])->st_line = '\0';
		return (1);
	}
	if (chr != NULL)
	{
 		while(new_line[fd]->st_line[i] != '\0')
 		{
 			if(new_line[fd]->st_line[i] == '\n')
 			{
 			*chr = '\0';
 			*line = ft_strdup(new_line[fd]->st_line);
 			new_line[fd]->st_line = ft_strdup(chr + 1);
 			return (1);
 			}
 			i++;
 		}
 	}
 	if (j != 0 || new_line[fd] == NULL || new_line[fd]->st_line[0] == '\0')
    {
        if (!j && *line)
            *line = NULL;
        return (j);
    }
 	return (0);
}
