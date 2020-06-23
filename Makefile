
NAME = asmy
SRC = get_label.c utillits.c utillits2.c add_args.c skip.c ft_free.c bait_get1.c \
bait_get2.c must_be.c valid_header.c main.c parce.c parce_code.c valid_args.c parce_arg.c \
error.c binary_code.c measure_size.c measure_typeargs.c command.c
#SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
OBJ2 = ./ft_printf/*.o
INC = asm.h
INCLUDES = -I./includes

FLAGS = -Wall -Werror -Wextra -g

all: $(OBJ)
	make -C libft/
	make -C ft_printf/
	gcc $(OBJ) $(OBJ2) -L. libft/libft.a -o $(NAME)

.c.o:
	gcc -c $< $(INCLUDES)


clean:
	make clean -C libft/
	make fclean -C ft_printf/
	/bin/rm $(OBJ)

fclean: clean
	/bin/rm $(NAME)


re: clean all
