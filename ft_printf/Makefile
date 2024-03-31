NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_printf.c ft_print_str.c ft_print_dec.c ft_print_hex.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(NAME) $(OBJS)

re	: fclean all

.PHONY: all clean fclean re