# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 09:37:07 by abrault           #+#    #+#              #
#    Updated: 2013/12/22 13:23:40 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  ft_list.c

OBJ = main.o \
	  ft_list.o

FLAG = -Wall -Wextra -Werror

Xinc = -I/usr/X11R6/include

Xlib = -L/usr/X11R6/lib -lX11

lib = -L./libft/ -lft

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) $(Xinc)
	gcc $(FLAG) -o fdf $(OBJ) $(Xlib) $(lib)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: clean fclean $(NAME)

