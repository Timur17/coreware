NAME = asm
DIR_SOURCE = ./srcs/
SRC = $(wildcard $(DIR_SOURCE)*.c)
OBJ = $(SRC:.c=.o)
LIB_LIBFT = ./libft/libft.a
LIB_PRINTF = ./ft_printf/libftprintf.a
INCLUDES = -I./includes
FLAGS = -Wall -Werror -Wextra

all: $(OBJ)
	make -C libft/
	make -C ft_printf/
	gcc $(FLAGS) $(OBJ)  -L. $(LIB_LIBFT) -L. $(LIB_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
	make fclean -C libft/
	make fclean -C ft_printf/
	/bin/rm $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all
