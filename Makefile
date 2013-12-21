# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 09:37:07 by abrault           #+#    #+#              #
#    Updated: 2013/12/21 14:05:38 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  ft_list.c

OBJ = main.o \
	  ft_list.o

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) -I/usr/X11R6/include
	gcc $(FLAG) -o fdf $(OBJ) -L/usr/X11R6/lib -lX11 -L. -lft

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: clean fclean $(NAME)

