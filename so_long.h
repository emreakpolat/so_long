/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:35 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/17 16:15:44 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define BUFFER_SIZE 42

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include  "minilibx/mlx.h"
#include "ft_printf/ft_printf.h"

typedef struct so_long
{
    int game_height;
    int game_width;
    void *init; 
    void *win;
    void *wall;
    void *character;
    void *coin;
    void *door;
    void *floor;
    char **map;
    int player_x;
    int player_y;
    int collectible;
    int collected;
    int moves;
    
} t_general;


char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(const char *s, int c);
void error(char *str);
void map_control(char **map);
void flood_fill_check(char **map, int i, int x, int y);
int	ft_strlen_forgnl(char *s);
void free_map(char **map);
void free_all(t_general *game);
int close_window(t_general *game);
int	character_move(int keycode, t_general *game);

void player_up(t_general *game);
void player_down(t_general *game);
void player_left(t_general *game);
void player_right(t_general *game);
t_general create_map(t_general game, char **map);
//sil

#endif