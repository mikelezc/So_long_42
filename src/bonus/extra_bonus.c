/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:46:07 by mlezcano          #+#    #+#             */
/*   Updated: 2023/12/14 18:30:27 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mov_display(t_game *game)
{
	char *mov_str = ft_itoa(game->pl_mov);

	if (mov_str == NULL)
		return ;
	mlx_string_put(game->mlx, game->mlx_win,
		game->pxl * game->map_x * (0.84), 10, 0xFFFFFF,
		"Movements: ");
	mlx_string_put(game->mlx, game->mlx_win,
		game->pxl * game->map_x * (0.95), 10, 0xFFFFFF,
		mov_str);
	free(mov_str);
}

void	ft_put_enemy(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./xpm/black_hole.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_enemy(int keyhook, t_game *game)
{
	if (((keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] == 'K')
		|| (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] == 'K')
		|| (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] == 'K')
		|| (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] == 'K')))
	{
		ft_printf("You have been absorved into the black hole!\n");
		ft_close_window(game);
	}
}
