/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:43:30 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/17 15:39:38 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char **flood_fill(char **map, int y, int x)
{
    if (map[y][x] == '1')
        return (0);

    map[y][x] = '1';

    
    flood_fill(map, (y + 1), x);
    flood_fill(map, (y - 1), x);
    flood_fill(map, y, (x + 1));
    flood_fill(map, y, (x - 1));
    return (map);
}

static char **map_copy(char **cpy_map, char **map, int size)
{
    int i;
    int j;

    cpy_map = malloc(sizeof(char *) * (size + 1));
    i = 0;
    while (map[i])
    {
        cpy_map[i] = malloc(ft_strlen(map[i]) + 1);
        j = 0;
        while (map[i][j])
        {
            cpy_map[i][j] = map[i][j];
            j++;
        }
        cpy_map[i][j] = '\0';
        i++;
    }
    cpy_map[i] = NULL;
    return (cpy_map);
}

static void accessible_control(char **map,char **original_map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P' || map[i][j] == 'E' ||  map[i][j] == 'C' )
            {
                free_map(map);
                free_map(original_map);
                error("Error\nInaccessible location on the map\n");
            }
            j++;
        }
        i++;
    }
}



void flood_fill_check(char **map, int i, int x, int y)
{
    char **copy_map;
    copy_map = NULL;
    copy_map = map_copy(copy_map, map, (i + 1));

    while (copy_map[y][x] != 'P' && copy_map[y][x] != '\0')
    {
        if (map[y][x] == '\n' || map[y][x] == '\0')
        {
            y++;
            x = 0;
        }
        x++;
    }
    
    copy_map = flood_fill(copy_map, y, x);
    accessible_control(copy_map, map);
    free_map(copy_map);
}
