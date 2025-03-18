/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:35 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/18 11:36:36 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 42

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include  "minilibx/mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct so_long
{
	char	**map;
	void	*character;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*door;
	void	*init;
	void	*win;
	int		collectible;
	int		game_height;
	int		game_width;
	int		collected;
	int		player_x;
	int		player_y;
	int		moves;
}	t_general;

int			ft_strlen_forgnl(char *s);
int			close_window(t_general *game);
int			character_move(int keycode, t_general *game);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		**gnl_read(int fd, char **av);
void		error(char *str);
void		free_map(char **map);
void		free_all(t_general *game);
void		map_control(char **map);
void		flood_fill_check(char **map, int i, int x, int y);
void		mlx_all_add(char **map, t_general *game);
void		rectangle_check(char **map, int i, int x, int y);
void		player_up(t_general *game);
void		player_down(t_general *game);
void		player_left(t_general *game);
void		player_right(t_general *game);
void		find_collectible_and_player(t_general *game, char **map);

t_general	create_map(t_general game, char **map);

#endif