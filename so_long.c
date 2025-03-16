/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:26 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/16 12:39:21 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(char *str)
{
    write(1, str, ft_strlen(str));
    exit(EXIT_FAILURE);
}

static char **gnl_read(int fd, char **av)
{
    int i;
    int line_count;
    char *line;
    char **map;

    line_count = 0;
    while ((line = get_next_line(fd)) != NULL)
        line_count++;
    free(line);
    close(fd);

    map =(char **)malloc(sizeof(char **) * (line_count + 1));
    fd = open(av[1], O_RDONLY);

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[i] =(char *)malloc(sizeof(char *) * ft_strlen(line));
        map[i] = line;
        i++;
    }
    map[i] = NULL;
    return (map);
}

static void     find_collectible_and_player(t_general *game, char **map)
{
    int i;
    int j;

    i = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->collectible = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                game->player_y = i;
                game->player_x = j;
            }
            else if(map[i][j] == 'C')
                game->collectible++;
            j++;
        }
        i++;
    }
}

static int ft_strlen_for_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int main(int ac, char **av)
{
    int fd;
    char **map;
    t_general game;


    fd = open(av[1], O_RDONLY);
    map = gnl_read(fd, av);
    if (ac == 2)
    {
        map_control(map);
        flood_fill_check(map, ft_strlen_for_map(map), 0, 0);
        find_collectible_and_player(&game, map);
        game = create_map(game, map);
    }
    else
        exit(1);
    close(fd);
}
