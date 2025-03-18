NAME = libftprintf.a

SRC = ft_printf.c ft_num.c ft_str.c 

OBJS = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re