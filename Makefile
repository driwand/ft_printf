
SRC = utils.c \
	  iterate_flags.c

CC = gcc
MAIN = ft_printf.c
#@make -C libft && make -C libft clean

all:
	$(CC) $(MAIN) $(SRC) -L./libft -lft
	./a.out
.SILENT:
