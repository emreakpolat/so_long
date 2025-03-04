# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 08:19:37 by makpolat          #+#    #+#              #
#    Updated: 2025/03/04 08:44:19 by makpolat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC	= so_long.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar crs


all: $(NAME)

$(NAME): $(OBJS)
	@make -C minilibx-linux/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./minilibx-linux/libmlx.a -lX11 -lXext -lm
	@echo "Compilation done"

clean:
	@make clean -C minilibx-linux/
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re