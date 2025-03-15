/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:40:59 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/15 13:57:14 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void player_up(t_general *game)
{
    if (game->map[game->player_y - 1][game->player_x] != '1')
    {
        if (game->map[game->player_y - 1][game->player_x] == 'C')
            game->collected++;
        if ((game->map[game->player_y - 1][game->player_x] == 'E') && (game->collectible == game->collected))
        {
            ft_printf("Awesome you cut all the skeletons!, Congratulations\n");
            exit(EXIT_SUCCESS);
        }
        if (game->map[game->player_y - 1][game->player_x] == 'E' && (game->collectible != game->collected))
        {
            return ;
        }
        
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->player_y -= 1;
        game->moves++;
        ft_printf("Moves: %d\n", game->moves);
    }
}
void player_down(t_general *game)
{
    if (game->map[game->player_y + 1][game->player_x] != '1')
    {
        if (game->map[game->player_y + 1][game->player_x] == 'C')
            game->collected++;
        if ((game->map[game->player_y + 1][game->player_x] == 'E') && (game->collectible == game->collected))
        {
            ft_printf("Awesome you cut all the skeletons!, Congratulations\n");
            exit(EXIT_SUCCESS);
        }
         if (game->map[game->player_y + 1][game->player_x] == 'E' && (game->collectible != game->collected))
        {
            return ;
        }
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->player_y += 1;
        game->moves++;
        ft_printf("Moves: %d\n", game->moves);
    }
}

void player_left(t_general *game)
{
    if (game->map[game->player_y][game->player_x + 1] != '1')
    {
        if (game->map[game->player_y][game->player_x + 1] == 'C')
            game->collected++;
        if ((game->map[game->player_y][game->player_x + 1] == 'E') && (game->collectible == game->collected))
        {
            ft_printf("Awesome you cut all the skeletons!, Congratulations\n");
            exit(EXIT_SUCCESS);
        }
         if (game->map[game->player_y][game->player_x + 1] == 'E' && (game->collectible != game->collected))
        {
            return ;
        }
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->player_x += 1;
        game->moves++;
        ft_printf("Moves: %d\n", game->moves);
    }
}


void player_right(t_general *game)
{
    if (game->map[game->player_y][game->player_x - 1] != '1')
    {
        if (game->map[game->player_y][game->player_x - 1] == 'C')
            game->collected++;
        if ((game->map[game->player_y][game->player_x - 1] == 'E') && (game->collectible == game->collected))
        {
            ft_printf("Awesome you cut all the skeletons!, Congratulations\n");
            exit(EXIT_SUCCESS);
        }
         if (game->map[game->player_y][game->player_x - 1] == 'E' && (game->collectible != game->collected))
        {
            return ;
        }
        game->map[game->player_y][game->player_x] = '0';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->player_x -= 1;
        game->moves++;
        ft_printf("Moves: %d\n", game->moves);
    }
}