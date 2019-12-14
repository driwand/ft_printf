
NAME = libftprintf.a
NAMELIBFT = libft.a
LIBFT = libft
MAKE = make -C
FLAGS = -Wall -Wextra -Werror
CC = gcc
AR= ar rcs

SRC = ft_printf.c \
		utils.c \
		utils_sec.c \
		iterate_flags.c \
		print_hexa.c \
		print_string.c \
		print_address.c \
		print_integer.c \
		print_unsigned.c \
		utilis_int.c \
	
SRC_LIBFT = ft_atoi.c \
		ft_bzero.c  \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strmapi.c \
		ft_lstreverse.c \
		ft_lstat.c

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(addprefix $(LIBFT)/,$(SRC_LIBFT:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIBFT)
	$(AR) $(NAME) $(OBJ) $(OBJ_LIBFT)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f libft/$(NAMELIBFT)

re: fclean all
