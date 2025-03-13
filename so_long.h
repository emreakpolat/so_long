/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:35 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/13 16:05:58 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define BUFFER_SIZE 42

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include  "minilibx/mlx.h"

typedef struct so_long
{
    int game_height;
    int game_width;
    void *init; 
    void *win;
    void *wall;
    void *character;
    
} t_general;

int ft_strlen(char *s);
char *get_next_line(int fd);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(const char *s, int c);
void error(char *str);
void map_control(char **map);
void flood_fill_check(char **map, int i, int x, int y);


t_general create_map(t_general game, char **map);
//sil
void map_printf(char **map);

#endif