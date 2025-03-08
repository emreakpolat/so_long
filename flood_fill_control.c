/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 21:43:30 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/08 22:58:18 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(char **map, int y, int x)
{
    if (map[y][x] == 1)
        return;

    map[y][x] = 1;

    flood_fill(map, y + 1, x);
    flood_fill(map, y - 1, x);
    flood_fill(map, y, x + 1);
    flood_fill(map, y, x - 1);
}

void flood_fill_check(char **map)
{
    int i;
    int x;
    int y;
    char **copy_map;

    copy_map = malloc(5);
    
    i = 0;
    while (map[i])
    {
        copy_map[i] = malloc(sizeof(14));
        copy_map[i] = map[i];
        i++;
    }
    x = 0;
    y = 0;
    while (copy_map[y][x] != 'P' && map[y][x] != '\0')
    {
        if (map[y][x] == '\n' || map[y][x] == '\0')
        {
            y++;
            x = 0;
        }
        x++;
    }
   // flood_fill(copy_map,y,x);
    //printf("x=%d y=%d\n",x,y);
    copy_map[0][0]='C';
    map_printf(copy_map);
    printf("\n------\n");
    map_printf(map);
}
