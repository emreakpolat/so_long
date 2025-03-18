/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:41:46 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/18 11:43:02 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_forgnl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen_forgnl(s1)
			+ ft_strlen_forgnl(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	close_window(t_general *game)
{
	mlx_destroy_image(game->init, game->character);
	mlx_destroy_image(game->init, game->coin);
	mlx_destroy_image(game->init, game->floor);
	mlx_destroy_image(game->init, game->door);
	mlx_destroy_image(game->init, game->wall);
	mlx_destroy_window(game->init, game->win);
	mlx_destroy_display(game->init);
	free_map(game->map);
	free(game->init);
	exit(0);
}

void	find_collectible_and_player(t_general *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectible = 0;
	game->collected = 0;
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
			else if (map[i][j] == 'C')
				game->collectible++;
			j++;
		}
		i++;
	}
}
