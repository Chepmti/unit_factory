# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpanasen <mpanasen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 19:48:21 by mpanasen          #+#    #+#              #
#    Updated: 2017/12/06 18:28:42 by mpanasen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	main.c\
		cordinats.c\
		create_map.c\
		ft_valid.c\
		move_figur.c\
		readwrite.c\

OBJ = $(SRC:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(OBJ) libft/libft.a

%.o: ./%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.NOTPARALLEL: all clean fclean re
