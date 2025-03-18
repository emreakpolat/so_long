/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:14:26 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/18 11:38:34 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

static int	ft_strlen_for_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	av_check(int ac, char **av)
{
	int	i;

	if (ac != 2)
		error("Error\nToo many arguments\n");
	i = 0;
	while (av[1])
	{
		while (av[1][i])
			i++;
		if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' ||
			av[1][i - 3] != 'b' || av[1][i - 4] != '.')
			error("Error\nThe map must have a '.ber' extension.\n");
		else
			break ;
	}
}

int	main(int ac, char **av)
{
	int			fd;
	char		**map;
	t_general	game;

	av_check(ac, av);
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
	close(fd);
}
