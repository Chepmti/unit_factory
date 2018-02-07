/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:30:27 by mchepil           #+#    #+#             */
/*   Updated: 2017/12/20 17:30:44 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coordinates(char *r, t_xy *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (r[i] != '\0')
	{
		if (r[i] == '#')
		{
			list->x[j] = i % 5;
			list->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

int		blocks(char *r)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (r[i] != '\0')
	{
		if (r[i] == '#')
			count++;
		i++;
	}
	return (count / 4);
}

t_xy	*memory_for_blocks(char *r)
{
	int count;
	int pp;
	t_xy *list;
	t_xy *tmp;
	char lett;

	count = blocks(r);
	lett = 'A';
	pp = 0;
	if (!(list = (t_xy*)malloc(sizeof(t_xy))))
		return (NULL);
	tmp = list;
	while (count > 0)
	{
		list->lett = lett;
		coordinates(ft_strsub(r, pp, 20), list);
		if (!(list->next = (t_xy*)malloc(sizeof(t_xy))))
				return (NULL);
		list = list->next;
		lett++;
		count--;
		pp += 21;
	}
	list->next = NULL;
	return (tmp);
}
