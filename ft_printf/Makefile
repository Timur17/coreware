# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 12:33:09 by lbritni           #+#    #+#              #
#    Updated: 2020/06/26 17:06:58 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OUT = *.o
SRC1 = *.c libft/*.c
HEADERS = printf.h libft/libft.h

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c -std=c99 $(SRC1) $(HEADERS) 
	@ar rc $(NAME) *.o;
	@ranlib $(NAME);

clean:
	@/bin/rm -f $(OUT)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *h.gch
	@/bin/rm -f libft/libft.a
	@/bin/rm -f libft/*h.gch

re: fclean all

comp: fclean all clean
	@gcc -o check main.c -L ./ -lftprintf
