/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:26 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/04 13:24:08 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(char *str)
{
    write(1, str, ft_strlen(str));
    exit(EXIT_FAILURE);
}

void free_function(t_gnl *root)
{
    int i = 0;
    
    while (root->map[i])
    {
        free(root->map[i]);
        i++;
    }
    free(root->map);
    free(root);
}
int main()
{
    int line_count;
    int fd = open("map.ber", O_RDONLY);
    char *line;
    char **map;

    line_count = 0;
    while ((line = get_next_line(fd)) != NULL)
        line_count++;
    free(line);
    close(fd);
    map =(char **)malloc(sizeof(char **) * line_count);
    fd = open("map.ber", O_RDONLY);
    line_count = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[line_count] =(char *)malloc(sizeof(char *) * ft_strlen(line));
        map[line_count] = line;
        line_count++;
    }
    line_count = 0;
    while (map[line_count])
    {
        map_control(map);
        line_count++;
    }
}
