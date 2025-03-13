/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:59:55 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/13 14:06:20 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void find_height_and_widht(char **map, t_general *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        while (map[i][j])
            j++;
        i++;
    }

    game->game_height = i;
    game->game_width = j;
}

t_general create_map(t_general game, char **map)
{
    find_height_and_widht(map, &game);

    game.init=mlx_init();
    game.win=mlx_new_window(game.init, (64 * game.game_width) ,(64 * game.game_height) ,"hollao WOrld42");
    mlx_loop(game.init);
    
    return game;
}