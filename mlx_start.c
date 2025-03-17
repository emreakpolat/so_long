/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:59:55 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/17 13:47:55 by makpolat         ###   ########.fr       */
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
    game->floor = mlx_xpm_file_to_image(game->init, "texture/back_ground.xpm", &width, &height);
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
                mlx_put_image_to_window(game->init, game->win, game->wall, (j * 64), (i * 64));
            else if(map[i][j] == 'P')
                mlx_put_image_to_window(game->init, game->win, game->character, (j * 64), (i * 64));
            else if(map[i][j] == 'C')
                mlx_put_image_to_window(game->init,game->win, game->coin, (j * 64), (i * 64));
            else if(map[i][j] == 'E')
                mlx_put_image_to_window(game->init,game->win, game->door, (j * 64), (i * 64));
            else if(map[i][j] == '0')
                mlx_put_image_to_window(game->init,game->win, game->floor, (j * 64), (i * 64));
            j++;
        }
        i++;
    }
    
}

int close_window(t_general *game)
{
    mlx_destroy_image(game->init, game->character);
	mlx_destroy_image(game->init, game->coin);
	mlx_destroy_image(game->init, game->floor);
	mlx_destroy_image(game->init, game->door);
	mlx_destroy_image(game->init, game->wall);
	mlx_destroy_window(game->init, game->win);
	mlx_destroy_display(game->init);
	free(game->init);
    exit(0);
}


static int character_move(int keycode, t_general *game)
{
    if (keycode == 65307)
    {
        close_window(game);
        exit(EXIT_SUCCESS);
    }
    if (keycode == 119 || keycode == 65362)
        player_up(game);
    if (keycode == 100 || keycode ==  65363)
        player_left(game);
    if (keycode == 97 || keycode == 65361)
        player_right(game);
    if (keycode == 115  || keycode == 65364)
       player_down(game);
    mlx_all_add(game->map, game);
    return (0);
}


// void free_all(t_general *game)
// {
//     if (game->win)
//         mlx_destroy_window(game->init, game->win);
//     if (game->init)
//         mlx_destroy_display(game->init);
//     free_map(game->map);
//     free(game->init);
//     free(game->character);
//     free(game->coin);
//     free(game->door);
//     free(game->floor);
//     free(game->wall);
//     free(game);
// }


t_general create_map(t_general game, char **map)
{
    find_height_and_widht(map, &game);

    game.map = map;
    game.moves = 0;
    game.init = mlx_init();
    game.win=mlx_new_window(game.init, (64 * game.game_width) ,(64 * game.game_height) ,"hollao WOrld42");
    mlx_file_add(&game);
    mlx_all_add(map, &game);
    free_map(map);
    mlx_key_hook(game.win,character_move,&game);
	mlx_hook(game.win, 17, 1, close_window, &game);
    mlx_loop(game.init);
    
    return (game);
}
