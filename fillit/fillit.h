/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpanasen <mpanasen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:35:34 by mpanasen          #+#    #+#             */
/*   Updated: 2017/12/25 16:35:43 by mpanasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_xy
{
	int x[4];
	int y[4];
	char lett;
	struct s_xy *next;
}	t_xy;

char				**del_figur(char **map, t_xy *cor, int size);
char				**add_figur(char **map, t_xy *cor, int size);
void				coordinates(char *r, t_xy *list);
int					blocks(char *r);
t_xy				*memory_for_blocks(char *r);
int 				ft_map_size(char *r);
char				**ft_map(char **map, int i);
t_xy				add_cordinates(char *r);
int					valid_check1(char *r, int j);
int					valid_check2(char *r, int j);
int					valid_finish(char *r);
void				move_cor(t_xy *cor, int x, int y);
int					move_to_tetri(char **map, t_xy *cor, int size);
char				**move_please(char **map, t_xy *cor, int size);
void				result(char *r, t_xy *cor);
void				out_map(char **map);
char				*read_write(int fd);

#endif
