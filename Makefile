
SRC = utils.c \
	  utils_sec.c \
	  iterate_flags.c \
	  print_string.c \
	  print_address.c \
	  print_integer.c

CC = gcc #-Wall -Wextra -Werror
MAIN = ft_printf.c
#@make -C libft && make -C libft clean

all:
	$(CC) $(MAIN) $(SRC) -L./libft -lft
	./a.out
.SILENT:
