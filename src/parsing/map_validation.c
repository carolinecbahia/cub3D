/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:51:57 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:23:38 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//TODO validate_identifiers()

int	validate_map_char(char c)
{
	if (c == WALL || c == EMPTY || c == PLAYER_E || c == PLAYER_E
		|| c == PLAYER_N || c == PLAYER_S || c == PLAYER_W)
		return (1);
	return (0);
}

//TODO validate_player()

//TODO validate_borders()

//TODO validate_closed_map()

int	validate_file(char *filename)
{
	int		fd;
	t_map	map;

	map = init_map(filename);
	(void)map;
	if (!check_file_extension(filename, ".cub"))
		return (0);
	fd = open_file(filename);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	validate_map_content(t_map *map __attribute__((unused)))
{
	return (0);
}

int		validate_map(t_map *map)
{
	if (!validate_file(map->map_path))
		return (0);
	if(!validate_texture_path(map))
		return (0);
	if (!validate_rgb(map))
		return (0);
	if (!validate_map_content(map))
		return (0);
	return (1);
}