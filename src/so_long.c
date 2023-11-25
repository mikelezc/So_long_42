/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:28:59 by mlezcano          #+#    #+#             */
/*   Updated: 2023/11/23 18:46:24 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include
void ft_check_maps(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error: Invalid number of arguments.\n Please try again\n");
		exit(0);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_printf("Error: Invalid file type. \n It only accepts *.ber\n Please try again\n");
		exit (1);
	}	
}

int	main(int argc, char **argv)
{
	ft_check_maps(argc, argv);
	game_start(argv[1]);
}
