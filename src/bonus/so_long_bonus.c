/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:41:12 by mlezcano          #+#    #+#             */
/*   Updated: 2023/12/15 10:48:41 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_window(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y, "Dark matter quest");
	ft_fill_window(game);
}

void	ft_map_ok(char **argv, t_game *game)
{
	int		i;
	int		fd;
	char	*buffer;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (fd == -1)
	{
		ft_printf("Error, can't open file.\n");
		exit (1);
	}
	buffer = ft_read_map(fd);
	ft_check_items(buffer, game);
	game->map = ft_split(buffer, '\n');
	free(buffer);
	while (game->map[0][i] != '\0')
	{
		game->map_x++;
		i++;
	}
	ft_check_map_is_square(buffer, game);
	close(fd);
}

void	ft_set_struct(t_game *game)
{
	game->map_x = 0;
	game->map_y = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
	game->pxl = 0;
	game->player = 0;
	game->pl_x = 0;
	game->pl_y = 0;
	game->pl_mov = 0;
	game->pl_dir = "./xpm/down.xpm";
	game->collect = 0;
	game->exit = 0;
	game->itinerary_exit = 0;
	game->itinerary_items = 0;
	game->itinerary_perso_x = 0;
	game->itinerary_perso_y = 0;
}

void	ft_is_valid_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error, invalid arguments:\n");
		ft_printf("Please, insert the map name after the executable file\n");
		exit(1);
	}
	valid_ber(argv[1], ".ber");
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_is_valid_arguments(argc, argv);
	ft_set_struct(&game);
	ft_map_ok(argv, &game);
	if (ft_itinerary_ok(&game) == 0)
		return (free_2_array(game.map), 0);
	ft_window(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_keyboard, &game);
	mlx_hook(game.mlx_win, 17, 1L << 5, ft_close_window, &game);
	mlx_loop(game.mlx);
	exit(0);
	return (0);
}
