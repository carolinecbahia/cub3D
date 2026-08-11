/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:08:02 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/11 11:44:17 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return_error("File not opened!\n", -1);
	}
	return (fd);
}

// void	read_lines(void)
// {

// }

t_map	init_map(char *filename)
{
	t_map	map;

	map.map_path = ft_strdup(filename);
	map.grid = NULL;
	map.width = 0;
	map.height = 0;
	ft_memset(map.textures_path, 0, 4);
	map.floor_color = 0;
	map.ceiling_color = 0;
	map.player_x = 0;
	map.player_y = 0;
	map.player_dir = 0;
	return (map);
}
