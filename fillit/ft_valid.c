/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchepil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:54:00 by mchepil           #+#    #+#             */
/*   Updated: 2017/12/20 12:54:21 by mchepil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_check1(char *r, int j)
{
	int dot;
	int hesh;
	int new_line;
	int i;

	dot = 0;
	hesh = 0;
	new_line = 0;
	i = 0;
	while (r[i] != '\0' && i + j < 20 + j)
	{
		if (r[i] == '.')
			dot++;
		if (r[i] == '#')
			hesh++;
		if (r[i] == '\n')
			new_line++;
		i++;
	}
	if (hesh == 4 && new_line == 4 && dot == 12)
			return (1);
		else
			return (0);
}

int		valid_check2(char *r, int j)
{
	int i;
	int hesh;

	hesh = 0;
	i = 0;
	while (i + j < 20 +j)
	{
		if (r[i + j] == '#')
		{
			if (r[i + j + 1] == '#' && (i + j + 1) < (20 + j))
				hesh++;
			if (r[i + j - 1] == '#' && (i + j - 1) > (0 + j))
				hesh++;
			if (r[i + j + 5] == '#' && (i + j + 5) < (20 +j))
				hesh++;
			if (r[i + j - 5] == '#' && (i + j - 5) > (0 + j))
				hesh++;
		}
		i++;
	}
	if (hesh == 6 || hesh == 8)
		return (1);
	else
		return (0);
}

int		valid_finish(char *r)
{
	int j;
	int i;

	i = 0;
	j = 0;

	if (!r)
		return (0);
	while (r[i + j] != '\0')
	{
		if (!(valid_check1(r, j) && valid_check2(r, j)))
			return (0);
		i = 19;
		if (r[i + j] == '\n' && r[i + j + 1] == '\0')
			return (1);
		if (r[i + j] == '\n' && r[i + j + 1] == '\n' && \
			(r[i + j + 2] == '.' || r[i + j + 2] == '#'))
			j = j + 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
