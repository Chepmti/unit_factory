/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpanasen <mpanasen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:56:16 by mpanasen          #+#    #+#             */
/*   Updated: 2017/12/18 13:50:14 by mpanasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	ft_map_size(char *r)
{
	int i;
	int hesh;

	i = 0;
	hesh = 0;
	while (r[i] != '\0')
	{
		if (r[i] == '#')
		hesh++;
	i++;
	}
	i = 0;
	while (hesh > i * i)
		i++;
	return (i);
}


//char    **ft_map(char **square, int i)
//{
//   int x;
//    int y;
//
//    y = 0;
//    if (!(square = (char**)malloc(sizeof(char*) * i + 1)))
  //      return (NULL);
   // while (y < i)
    //{
      //  if (!(square[y] = (char*)malloc(sizeof(char) * i + 1)))
       //     return (NULL);
        //x = 0;
        //while (x < i)
        //{
         //   square[y][x] = '.';
          //  x++;
        //}
        //square[y][x] = '\0';
        //y++;
    //}
    //square[y] = 0;
    //return (square);
//}

char	**ft_map(char **map, int i)
{
 	int d;
 	int j;

 	j = 0;
 	if (!(map = (char **)malloc(sizeof(char*) * (i + 1))))
 		return (0);
 	d = i;
 	while (d--)
 		if (!(map[j++] = (char *)malloc(i + 1)))
 			return (0);
 	d = 0;
 	j = 0;
 	while (j < i)	
 	{
 		while (d < i)
 			map[j][d++] = '.';
 		map[j][d] = '\0';
 		d = 0;
 		j++;
 	}
 	map[j] = NULL;
 	return (map);
}

char	**del_figur(char **map, t_xy *cor, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (map[x][y] == cor->lett)
			{
				map[x][y] = '.';
			}
			y++;
		}
		x++;
	}
	return (map);
}

char	**add_figur(char **map, t_xy *cor, int size)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (cor->x[i] == x && cor->y[i] == y)
			{
				map[x][y] = cor->lett;
				i++;
			}
			y++;
		}
		x++;
	}
	return (map);
}
