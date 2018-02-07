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

char	*ft_read_write_file(int fd)
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
		/*сдесь живет лик*/
		else if (file)
		{
			tmp = ft_strdup(file);
			free(file);
			file = ft_strjoin(tmp, buf);
			free(tmp);
		}
	}
	return (file);
}

t_lst	*add_list(t_lst *new)
{
	new = (t_lst *)malloc(sizeof(t_lst));
	new->st_line = NULL;
	return (new);
}

int		add_to_struct(t_lst *new_line, char **line)
{
	int				i;
	char			*chr;

	i = 0;
	chr = ft_strchr(new_line->st_line, '\n');
	if (chr == NULL && ft_strlen((new_line->st_line)) > 0)
	{
		*line = ft_strdup((new_line->st_line));
		*(new_line)->st_line = '\0';
		return (1);
	}
	if (chr != NULL)
	{
		while(new_line->st_line[i] != '\0')
		{
			if(new_line->st_line[i] == '\n')
			{
				*chr = '\0';
				*line = ft_strdup(new_line->st_line);
				new_line->st_line = ft_strdup(chr + 1);
				return (1);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	/*int				i;
	  char			*chr;*/
	static t_lst	*new_line[FD_MAX];

	if (fd < 0 || BUFF_SIZE <= 0 || !line || fd >= FD_MAX || read(fd, new_line[fd], 0) < 0)
		return (-1);
	if(!new_line[fd])
	{
		new_line[fd] = add_list(new_line[fd]);
		new_line[fd]->st_line = ft_read_write_file(fd);
	}
	if (!new_line[fd] || !new_line[fd]->st_line[0])
	{
		if (*line)
			*line = NULL;
		return (0);
	}
	return(add_to_struct(new_line[fd], line));
}
