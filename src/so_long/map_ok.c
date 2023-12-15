/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:41:12 by mlezcano          #+#    #+#             */
/*   Updated: 2023/12/15 11:14:00 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_is_square(char *buffer, t_game *game)
{
	game->map_area = ft_strlen(buffer) - game->map_y + 1;
	if (game->map_area != game->map_x * game->map_y)
	{
		ft_printf("Error!\nThe map has a wrong layout.\n");
		exit (1);
	}
	ft_check_x_limits(game);
	ft_check_y_limits(game);
}

void	ft_check_items(char *linemap, t_game *game)
{
	int	i;

	i = 0;
	while (linemap[i])
	{
		if (linemap[i] == 'P')
			game->player++;
		if (linemap[i] == 'C')
			game->collect++;
		if (linemap[i] == 'E')
			game->exit++;
		if (linemap[i] == '\n')
			game->map_y++;
		i++;
	}
	game->map_y++;
	if (game->player != 1 || game->collect < 1 || game->exit != 1)
	{
		ft_printf("Error\nIncorrect number items in the map\n");
		exit(1);
	}
}

char	*ft_line_constructor(char *line, char new_char)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = new_char;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	ft_is_null(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_map(int fd)
{
	char	new_char;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
		line = NULL;
	line = malloc(1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	while (!ft_is_null(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &new_char, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			ft_printf("Error\nThis map is empty!\n");
			free(line);
			exit(1);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = ft_line_constructor(line, new_char);
	}
	return (line);
}
