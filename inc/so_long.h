/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:44:30 by mlezcano          #+#    #+#             */
/*   Updated: 2023/12/17 20:04:05 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/inc/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

//Message types
# define MAP_ERR_EXIT "Error!\nCan't reach the exit on this map..."

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*file;
	int		map_x;
	int		map_y;
	int		map_area;
	int		x;
	int		y;
	int		pxl;
	int		player;
	int		pl_x;
	int		pl_y;
	int		pl_mov;
	char	*pl_dir;
	int		collect;
	int		exit;

	int		itinerary_exit;
	int		itinerary_items;
	int		itinerary_perso_x;
	int		itinerary_perso_y;
}	t_game;

//so_long
void		ft_is_valid_arguments(int argc, char **argv);
void		ft_set_struct(t_game *game);
void		ft_map_ok(char **argv, t_game *game);
void		ft_window(t_game *game);

//map_ok
char		*ft_read_map(int fd);
int			ft_is_null(char *line);
char		*ft_line_constructor(char	*line, char c);
void		ft_check_items(char *buffer, t_game *game);
void		ft_check_map_is_square(char *buffer, t_game *game);

//check_limits
void		ft_check_x_limits(t_game *game);
void		ft_check_y_limits(t_game *game);
void		ft_limits_error(void);

//itinerary_ok
int			ft_itinerary_ok(t_game *game);
int			ft_anyone_there(t_game *game, char **map);
void		iti_collects(t_game *game, char **map, int x, int y);
void		iti_exit(t_game *game, char **map, int x, int y);
void		ft_copy_map(t_game *game, char **map);

//window
void		ft_fill_window(t_game *game);
int			ft_total_collect(t_game *game);
void		ft_fill_floor(t_game *game);
int			ft_close_window(t_game *game);

//window_fill
void		ft_put_limits(t_game *game);
void		ft_put_floor(t_game *game);
void		ft_put_collect(t_game *game);
void		ft_put_player(t_game *game);
void		ft_put_exit(t_game *game);

//keyhook
int			ft_keyboard(int keyhook, t_game *game);
void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);

//utils
void		ft_valid_ber(char *map_name, char *ext);
void		free_2_array(char **arr);
void		printer(char *msg);
void		err_exit(void);
#endif