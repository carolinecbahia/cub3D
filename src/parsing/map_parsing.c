/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:55:18 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/24 13:22:04 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_map_start(char **file_lines)
{
	int	i;
	i = 0;
	while (file_lines[i])
	{
		if (is_empty_line(file_lines[i]) || find_colors(file_lines[i], 'F') 
			|| find_colors(file_lines[i], 'C') 
			||valid_texture_line(file_lines[i], 'N')
			|| valid_texture_line(file_lines[i], 'S')
			|| valid_texture_line(file_lines[i], 'W')
			|| valid_texture_line(file_lines[i], 'E'))
		{
			i++;
			continue ;
		}
		if (is_map_line(file_lines[i]))
			return (i);
		else
			return (return_error("Map line is invalid\n", 0));
	}
	return (return_error("Map not found in archive\n", 0));
}


static int read_map_size(char **file_lines, int start, t_map *map)
{
	int height;
	int	width;
	int	i;
	int	line_width;

	i = start;
	height = 0;
	width = 0;
	while(file_lines[i])
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

int	create_grid(t_map *map)
{
	char	**grid;
	int		i;

	grid = ft_calloc(map->height + 1, sizeof(char *));
	if (!grid)
		return (return_error("Malloc failed\n", 0));
	i = 0;
	while (i < map->height)
	{
		grid[i] = malloc((map->width + 1) * sizeof(char));
		if (!grid[i])
		{
			ft_free_matrix(grid);
			return (return_error("Malloc failed\n", 0));
		}
		i++;
	}
	grid[map->height] = NULL;
	map->grid = grid;
	return (1);
}

static	int	fill_map_grid(char **file_lines, int start, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (file_lines[start + i][j])
		{
			map->grid[i][j] = file_lines[start + i][j];
			j++;
		}
		while (j < map->width)
		{
			map->grid[i][j] = ' ';
			j++;
		}
		map->grid[i][map->width] = '\0';
		i++;
	}
	return (1);
}

int	find_player(t_map *map, int *px, int *py, char *dir)
{
	int	i;
	int	j;

	i = 0;
	while(i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
			{
				if (*dir != 0)
					return (return_error("Too many players\n", 0));
				*px = j;
				*py = i;
				*dir = map->grid[i][j];
			}
			j++;
		}
		i++;
	}
	if (*dir == 0)
		return (return_error("Player not found\n", 0));
	return (1);
}
