/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:26 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/17 13:42:50 by makpolat         ###   ########.fr       */
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
    {
        free(line);
        line_count++;
    }
    close(fd);

    map =(char **)malloc(sizeof(char *) * (line_count + 1));
    fd = open(av[1], O_RDONLY);

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
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

void free_map(char **map)
{
    int i = 0;
    if (!map)
        return;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    
}

int main(int ac, char **av)
{
    int fd;
    char **map;
    t_general game;

    int i = 0;
    if (ac != 2)
        exit(1);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error\nCannot open file: %s\n", av[1]);
        return (1);
    }
    map = gnl_read(fd, av);
    if (map == NULL)
    {
        free_map(map);
        close(fd);
        return (1);
    }
    map_control(map);
    flood_fill_check(map, ft_strlen_for_map(map), 0, 0);
    find_collectible_and_player(&game, map);
    game = create_map(game, map);
    //free_all(&game);
    close(fd);
}
