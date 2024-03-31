NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_printf.c ft_print_c_s_p.c ft_print_d_i_u.c ft_print_x_X_per.c


OBJ_FILES = $(SRCS:.c=.o)

$(NAME) : $(OBJ_FILES)
	ar cr $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

clean :
	rm -rf $(OBJ_FILES)

fclean :
	rm -rf $(NAME) $(OBJ_FILES)

re : fclean all

.PHONY : all clean fclean re