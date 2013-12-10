# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 09:37:07 by abrault           #+#    #+#              #
#    Updated: 2013/11/28 10:55:05 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all:	$(NAME) comp

$(NAME):
	gcc -c main.c -I/usr/X11R6/include

comp:
	gcc main.o -L/usr/X11R6/lib -lX11 -o $(NAME)

clean:
	rm -f main.o

fclean:
	rm -f $(NAME)

re: clean fclean $(NAME) comp
