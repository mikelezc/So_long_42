/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:07:44 by mlezcano          #+#    #+#             */
/*   Updated: 2023/12/17 20:03:49 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_valid_ber(char *map_name, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(map_name) - ft_strlen(ext);
	j = 0;
	while (map_name[i + j] && ext[j])
	{
		if (map_name[i + j] == ext[j])
			j++;
		else
		{
			ft_printf("Error!\nFile extension must be: .ber\n");
			exit(1);
		}
	}
}

void	free_2_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	printer(char *msg)
{
	ft_printf(msg);
	ft_printf("\n");
}

void	err_exit(void)
{
	ft_printf("Error.\n");
	exit(1);
}
