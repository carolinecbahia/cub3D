/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:55:59 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/21 22:09:26 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	find_player_pos(t_game *game, t_vectors *pos)
{
	int	x;
	int	y;

	y = 0;
	while (game->matrix[y])
	{
		x = 0;
		while (game->matrix[y][x])
		{
			if (game->matrix[y][x] == PLAYER)
			{
				pos->x = x;
				pos->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int check_map_borders(t_map map)
{
    
}

void	flood_fill(char **map, int x, int y, int allow_exit)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == WALL)
		return ;
	if (map[y][x] == VISITED)
		return ;
	if (map[y][x] == COLLECTIBLE || map[y][x] == EMPTY ||
		map[y][x] == EXIT || map[y][x] == PLAYER)
		map[y][x] = VISITED;
	flood_fill(map, x + 1, y, allow_exit);
	flood_fill(map, x - 1, y, allow_exit);
	flood_fill(map, x, y + 1, allow_exit);
	flood_fill(map, x, y - 1, allow_exit);
}

int	check_remaining(char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == COLLECTIBLE || map_copy[y][x] == EXIT)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_collectibles_remaining(char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == COLLECTIBLE)
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	path_validator(t_game *map_data)
{
	char		**map_copy;
	t_vectors	player_pos;

	find_player_pos(map_data, &player_pos);
	map_copy = dup_matrix(map_data->matrix);
	if (!map_copy)
		return (-1);
	flood_fill(map_copy, player_pos.x, player_pos.y, 0);
	if (check_collectibles_remaining(map_copy) != 0)
	{
		ft_free_matrix(map_copy);
		return (-1);
	}
	ft_free_matrix(map_copy);
	map_copy = dup_matrix(map_data->matrix);
	flood_fill(map_copy, player_pos.x, player_pos.y, 1);
	if (check_remaining(map_copy) != 0)
	{
		ft_free_matrix(map_copy);
		return (-1);
	}
	ft_free_matrix(map_copy);
	return (0);
}
