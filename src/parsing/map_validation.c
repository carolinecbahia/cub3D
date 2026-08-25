/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:51:57 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/25 14:31:04 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_borders(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == EMPTY || is_player(map->grid[i][j]))
			{
				if (i == 0 || i == map->height - 1 || j == map->width - 1
					|| j == 0)
					return (0);
				if (has_open_neighbor(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	flood_fill(t_map *map, int start_y, int start_x)
{
	int	**visited;
	int	i;
	int	result;

	if (!map || !map->grid)
		return (0);
	visited = ft_calloc(map->height, sizeof(int *));
	if (!visited)
		return (0);
	i = 0;
	while (i < map->height)
	{
		visited[i] = ft_calloc(map->width, sizeof(int));
		if (!visited[i])
			return (free_visited(visited, i, FALSE));
		i++;
	}
	result = flood_fill_iterative(map, visited, start_y, start_x);
	return (free_visited(visited, map->height, result));
}

int	validate_map_content(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->grid[i][j];
			if (!validate_map_char(c))
				return (return_error("╰┈➤ Invalid map character! 🗺️\n", 0));
			j++;
		}
		i++;
	}
	if (!find_player(map, &map->player_x,
			&map->player_y, &map->player_dir))
		return (0);
	if (!flood_fill(map, map->player_y, map->player_x))
		return (return_error("╰┈➤ Map is not closed! 🗺️\n", 0));
	if (!validate_borders(map))
		return (return_error("╰┈➤ Map is not closed! 🗺️\n", 0));
	return (1);
}
