/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:51:57 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 15:49:43 by anunes-o         ###   ########.fr       */
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

static int	flood_fill_recursive(char **grid, int **visited,
	int height, int width, int y, int x)
{
	if (y < 0 || y >= height || x < 0 || x >= width)
		return (0);
	if (visited[y][x])
		return (1);
	if (grid[y][x] == '1')
		return (1);
	if (grid[y][x] == ' ' || grid[y][x] == '\0')
		return (0);
	if (grid[y][x] != EMPTY && !is_player(grid[y][x]))
		return (1);
	visited[y][x] = 1;
	if (!flood_fill_recursive(grid, visited, height, width, y - 1, x))
		return (0);
	if (!flood_fill_recursive(grid, visited, height, width, y + 1, x))
		return (0);
	if (!flood_fill_recursive(grid, visited, height, width, y, x - 1))
		return (0);
	if (!flood_fill_recursive(grid, visited, height, width, y, x + 1))
		return (0);
	return (1);
}

int	flood_fill(t_map *map, int start_y, int start_x)
{
	int	**visited;
	int	i;

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
			return (0);
		i++;
	}
	if (!flood_fill_recursive(map->grid, visited, map->height,
			map->width, start_y, start_x))
	{
		i = 0;
		while (i < map->height)
			free(visited[i++]);
		free(visited);
		return (0);
	}
	i = 0;
	while (i < map->height)
		free(visited[i++]);
	free(visited);
	return (1);
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
				return (return_error("Invalid map character! 🗺️\n", 0));
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
