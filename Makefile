
NAME = asmy
SRC = add_args.c skip.c ft_free.c bait_get1.c bait_get2.c must_be.c un_utilits.c valid_header.c main.c parce.c parce_code.c valid_args.c parce_arg.c error.c binary_code.c measure_size.c measure_typeargs.c command.c
OBJ = $(SRC:.c=.o)
INC = asm.h

FLAGS = -Wall -Werror -Wextra -g

all: $(OBJ)
	make -C libft/
	gcc $(OBJ) -I $(INC) -L. libft/libft.a -o $(NAME)


clean:
	make clean -C libft/
	/bin/rm $(OBJ)

fclean: clean
	make fclean -C libft/
	/bin/rm $(NAME)


re: clean all
