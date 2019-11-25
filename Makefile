
all:
	@make -C libft && make -C libft clean
	gcc ft_printf.c -L./libft -lft
	./a.out
.SILENT:
