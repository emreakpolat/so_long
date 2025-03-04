/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:28:01 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/04 13:25:09 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void coin_check(char **map)
{
    int i;
    int j = 0;
    int coin_count;

    i = 0;
    coin_count = 0;
    while (map[i])
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
        error("There is no coin!\n");
}



void    map_control(char **map)
{
    coin_check(map);
    //wall_check()
    //character_check()
    

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