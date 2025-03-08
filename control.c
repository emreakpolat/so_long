/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:28:01 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/08 14:31:12 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void coin_check(char **map)
{
    int i;
    int j = 0;
    int coin_count;

    i = 0;
    coin_count = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                coin_count++;
            j++;
        }
        i++;
    }
    if (coin_count < 1)
        error("Error. There is no coin!\n");
}

static void     character_check(char **map)
{
    int i;
    int j;
    int character_count;

    i = 0;
    character_count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                character_count++;
            j++;
        }
        i++;
    }
    if (character_count != 1)
        error("Error. There is no character\n");
}

static void     door_check(char **map)
{
    int i;
    int j;
    int door_count;

    i = 0;
    door_count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' 
            && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
                error("Error. This is not a map\n");
            if (map[i][j] == 'E')
                door_count++;
            j++;
        }
        i++;
    }
    if (door_count != 1)
        error("Error. There is no exit door\n");
}

static void close_check(char **map, int y, int i)
{
    int j;
    
    j = 0;    
    while (map[i])
    {
        while ((map[0][j] != '\n' && map[0][j] != '\0'))
        {
            if (map[0][j] != '1')
                error("Error. Map is not close\n");
            j++;
        }
        j = 0;
        while ((map[y - 1][j] != '\n' && map[y - 1][j] != '\0'))
        {
            if (map[y - 1][j] != '1')
                error("Error. Map is not close\n");
            j++;
        }
        i++;
    }
}

static void     rectangle_check(char **map)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    x = 0;
    y = 0;
    while (map[i][x] != '\n')
        x++;
    while (map[y] != NULL && map[y][0] != '\n' && map[y][0] != '\0')
        y++;
    close_check(map, y , i);
    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\n' && map[i][j] != '\0')
            j++;
        if (j != x)
            error("Error. Map is not rectangular\n");
        if((map[i][j - 1] != '1') || (map[i][0] != '1'))
            error("Error. Map is not close\n");
        i++;
    }
}


void    map_control(char **map)
{
    if (map == NULL || *map == NULL)
        error("Error. There is no map\n");
    while (**map == '\n')
        error("Error. Map is newline\n");
    coin_check(map);
    character_check(map);
    door_check(map);
    rectangle_check(map);    
}

