
NAME = asmy
SRC = get_label.c utillits.c add_args.c skip.c ft_free.c bait_get1.c bait_get2.c must_be.c valid_header.c main.c parce.c parce_code.c valid_args.c parce_arg.c error.c binary_code.c measure_size.c measure_typeargs.c command.c
OBJ = $(SRC:.c=.o)
OBJ2 = ft_printf/*.o
INC = -includes/asm.h
FLAGS = -Wall -Werror -Wextra

all: $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(OBJ2) $(OBJ) $(OBJ2)  -L. libft/libft.a -o $(NAME)

clean:
	make clean -C libft/
	/bin/rm $(OBJ)

fclean: clean
	make fclean -C libft/
	/bin/rm $(NAME)


re: clean all