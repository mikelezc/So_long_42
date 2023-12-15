/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itinerary_ok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:53:27 by mlezcano          #+#    #+#             */
/*   Updated: 2023/12/14 16:45:11 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_position_player(t_game *game, char **map)
{
	while (game->itinerary_perso_y < game->map_y)
	{
		game->itinerary_perso_x = 0;
		while (game->itinerary_perso_x < game->map_x)
		{
			if (map[game->itinerary_perso_y][game->itinerary_perso_x] == 'P')
				return (1);
			game->itinerary_perso_x++;
		}
		game->itinerary_perso_y++;
	}
	return (0);
}

void	itinerary_c(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == 'C')
		game->itinerary_items++;
	if (map[y - 1][x] == '0' || map[y + 1][x] == '0' || map[y][x - 1] == '0'
			|| map[y][x + 1] == '0' || map[y - 1][x] == 'C'
			|| map[y + 1][x] == 'C' || map[y][x - 1] == 'C'
			|| map[y][x + 1] == 'C')
		map[y][x] = '.';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		itinerary_c(game, map, x, y - 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		itinerary_c(game, map, x, y + 1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		itinerary_c(game, map, x - 1, y);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		itinerary_c(game, map, x + 1, y);
	map[y][x] = '.';
}

void	itinerary_e(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == 'E')
		game->itinerary_exit++;
	if (map[y - 1][x] == '0' || map[y + 1][x] == '0' || map[y][x - 1] == '0'
			|| map[y][x + 1] == '0' || map[y - 1][x] == 'C'
			|| map[y + 1][x] == 'C' || map[y][x - 1] == 'C'
			|| map[y][x + 1] == 'C')
		map[y][x] = '.';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
		itinerary_e(game, map, x, y - 1);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
		itinerary_e(game, map, x, y + 1);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
		itinerary_e(game, map, x - 1, y);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
		itinerary_e(game, map, x + 1, y);
	map[y][x] = '.';
}

void	ft_copy_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_y)
	{
		map[i] = (char *)malloc(sizeof(char) * (game->map_x + 1));
		i++;
	}
	i = 0;
	while (i < game->map_y)
	{
		j = 0;
		while (j < game->map_x)
		{
			map[i][j] = game->map[i][j];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

int	ft_itinerary_ok(t_game *game)
{
	int		line;
	char	**map;

	line = 0;
	map = (char **)malloc(sizeof(char *) * (game->map_y + 1));
	ft_copy_map(game, map);
	if (!ft_position_player(game, map))
		return (free_2_array(map), 0);
	itinerary_c(game, map, game->itinerary_perso_x, game->itinerary_perso_y);
	if (game->itinerary_items != game->collect)
		return (free_2_array(map), printer(MAP_ERR_EXIT), 0);
	while (line < game->map_y)
		free(map[line++]);
	ft_copy_map(game, map);
	itinerary_e(game, map, game->itinerary_perso_x, game->itinerary_perso_y);
	line = 0;
	while (line < game->map_y)
		free(map[line++]);
	free(map);
	if (game->itinerary_exit != 1)
		return (printer(MAP_ERR_EXIT), 0);
	return (1);
}
