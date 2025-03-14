# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 08:19:37 by makpolat          #+#    #+#              #
#    Updated: 2025/03/14 13:54:17 by makpolat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
MLX_LIB=minilibx/libmlx.a

SRC	= so_long.c \
	get_next_line.c \
	so_long_utils.c \
	control.c \
	flood_fill_control.c \
	mlx_start.c \
	player_moves.c 

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -g 
RM = rm -f
AR = ar crs
MLX_FLAGS=-L minilibx -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx -s
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(MLX_LIB)

clean:
	@make clean -C minilibx/
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re