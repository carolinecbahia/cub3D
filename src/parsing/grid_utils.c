/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:43:34 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/13 13:02:37 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

int	is_player(char c)
{
	return (c == PLAYER_E || c == PLAYER_N 
		|| c == PLAYER_S || c == PLAYER_W );
}

int	validate_map_char(char c)
{
	if (c == WALL || c == EMPTY || c == ' ' || is_player(c))
		return (1);
	return (0);
}

int	has_open_neighbor(t_map *map, int i, int j)
{
	static const int	di[4] = {-1, 1, 0, 0};
	static const int	dj[4] = {0, 0, -1, 1};
	int					k;

	k = 0;
	while (k < 4)
	{
		if (map->grid[i + di[k]][j + dj[k]] == ' ')
			return (1);
		k++;
	}
	return (0);
}

int	read_map_size(char **file_lines, int start, t_map *map)
{
	int	height;
	int	width;
	int	i;
	int	line_width;

	i = start;
	height = 0;
	width = 0;
	while (file_lines[i])
	{
		if (is_empty_line(file_lines[i]))
			return (return_error("Empty line in map\n", 0));
		if (!(is_map_line(file_lines[i])))
			return (return_error("Invalid map\n", 0));
		line_width = ft_strlen(file_lines[i]);
		if (width < line_width)
			width = line_width;
		height++;
		i++;
	}
	map->height = height;
	map->width = width;
	return (1);
}
