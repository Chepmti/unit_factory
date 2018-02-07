# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchepil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/03 15:51:41 by mchepil           #+#    #+#              #
#    Updated: 2017/11/03 15:53:01 by mchepil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	 ft_strdup.c ft_strchr.c ft_strjoin.c ft_strlen.c

OSRC	=	ft_strdup.o ft_strchr.o ft_strjoin.o ft_strlen.o

MAKE	=	@make

FLAGS	=	-Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OSRC)
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OSRC)

%.o : %.c
	gcc $(FLAGS) -c $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all
