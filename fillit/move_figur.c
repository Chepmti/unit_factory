#include "fillit.h"


void	move_cor(t_xy *cor, int x, int y)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 10;
	j = 10;
	while (k < 4)
	{
		if (cor->x[k] < i)
			i = cor->x[k];
		if (cor->y[k] < j)
			j = cor->y[k];
		k++;
	}
	k = 0;
	while (k < 4)
	{
		cor->x[k] = cor->x[k] - i + x;
		cor->y[k] = cor->y[k] - j + y;
		k++;
	}
}

int		move_to_tetri(char **map, t_xy *cor, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if(cor->y[i] < size && cor->x[i] < size && \
				map[cor->y[i]][cor->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**move_please(char **map, t_xy *cor, int size)
{
	int i;
	int j;
	char **local;

	local = NULL;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			move_cor(cor, i, j);
			if (move_to_tetri(map, cor, size))
				local = move_please(add_figur(map, cor, size), 
					cor->next, size);
			if (local)
				return (local);
			map = del_figur(map, cor, size);
			i++;
		}
		j++;
	}
	return (NULL);
}

void	result(char *r, t_xy *cor)
{
	char **new_map;
	char **print_map;
	int x;

	x = ft_map_size(r);
	new_map = NULL;
	print_map = NULL;
	new_map = ft_map(new_map, x);
	while (!(print_map = move_please(new_map, cor, x)))
	{
		x++;
		free(new_map);
		new_map = ft_map(new_map, x);
	}
	out_map(print_map);
}

void	out_map(char **map)
{
	int i;

	if (map == NULL)
	{
		ft_putendl("error");
		return ;
	}
	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}