/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:26 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/07 15:35:31 by makpolat         ###   ########.fr       */
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
int main(int ac, char **av)
{
    if (ac == 2)
    {
        int fd;
        char **map;

        fd = open(av[1], O_RDONLY);
        map = gnl_read(fd, av);

        map_control(map);
    }
}
