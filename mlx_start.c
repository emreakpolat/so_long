/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:59:55 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/13 16:54:17 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void find_height_and_widht(char **map, t_general *game)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
            j++;
        i++;
    }

    game->game_height = i;
    game->game_width = j;
}

static void mlx_file_add(t_general *game)
{
    int width;
    int height;


    game->wall = mlx_xpm_file_to_image(game->init, "texture/wall.xpm", &width, &height);
    game->character = mlx_xpm_file_to_image(game->init, "texture/warrior.xpm", &width, &height);
    game->coin = mlx_xpm_file_to_image(game->init, "texture/skeleton.xpm", &width, &height);
    game->door = mlx_xpm_file_to_image(game->init, "texture/door.xpm", &width, &height);
}

static void mlx_all_add(char **map, t_general *game)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(game->init, game->win, game->wall, j * 64, i * 64);
            else if(map[i][j] == 'P')
                mlx_put_image_to_window(game->init, game->win, game->character, j * 64, i * 64);
            else if(map[i][j] == 'C')
                mlx_put_image_to_window(game->init,game->win, game->coin, j * 64, i * 64);
            else if(map[i][j] == 'E')
                mlx_put_image_to_window(game->init,game->win, game->door, j * 64, i * 64);
            j++;
        }
        i++;
    }
    
}

t_general create_map(t_general game, char **map)
{
    find_height_and_widht(map, &game);

    game.init=mlx_init();
    game.win=mlx_new_window(game.init, (64 * game.game_width) ,(64 * game.game_height) ,"hollao WOrld42");
    mlx_file_add(&game);
    mlx_all_add(map, &game);
    
    mlx_loop(game.init);
    
    
    return (game);
}