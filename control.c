/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:28:01 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/04 15:11:22 by makpolat         ###   ########.fr       */
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
        printf("%s\n ", map[i]);
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
            if (map[i][j] == 'E')
                door_count++;
            j++;
        }
        i++;
    }
    if (door_count != 1)
        error("Error. There is no exit door\n");
}

void    map_control(char **map)
{
    if (map == NULL)
        error("Error. There is no map\n");
    
    coin_check(map);
    printf("burada\n");
    character_check(map);
    door_check(map);
    //wall_check()
    

}
    // int i;

    // i = 0;
    // while (line != NULL)
    // {
    //     printf("line: %s\n", line);

    //     if (line[i] != '1' && (line[i] != '\n' && line[i] != '\0'))
    //     {
    //         printf("line: %s\n", line);
    //         error("Hata, duvar yok!\n");
    //     }
    //     if(line[i] == '\n')
    //         i = 0;
    //     i++;
    //     line = get_next_line(fd);
    // }
