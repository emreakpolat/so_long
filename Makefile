# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 08:19:37 by makpolat          #+#    #+#              #
#    Updated: 2025/03/15 15:47:24 by makpolat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
MLX_LIB = minilibx/libmlx.a

SRC	= so_long.c \
	get_next_line.c \
	so_long_utils.c \
	control.c \
	flood_fill_control.c \
	mlx_start.c \
	player_moves.c 

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX_FLAGS=-L minilibx -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd
FT_PRINTF = ft_printf
PRINTF = $(FT_PRINTF)/libftprintf.a

all: printf $(NAME)

printf:
	@make -C $(FT_PRINTF)

$(NAME): $(OBJS)
	make -C ./minilibx -s
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(MLX_LIB) $(PRINTF)

clean:
	@make clean -C minilibx/
	@make clean -C $(FT_PRINTF)
	@$(RM) $(OBJS)

fclean:	clean
	@make clean -C $(FT_PRINTF)
	$(RM) $(PRINTF)
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re