/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:51:57 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/21 22:08:57 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_map_elements(t_game *game)
{
	int	x;
	int	y;

	game->collectible_count = 0;
	game->player_count = 0;
	game->exit_count = 0;
	y = 0;
	while (game->matrix[y] != NULL)
	{
		x = 0;
		while (game->matrix[y][x] != '\0')
		{
			if (game->matrix[y][x] == COLLECTIBLE)
				game->collectible_count++;
			else if (game->matrix[y][x] == EXIT)
				game->exit_count++;
			else if (game->matrix[y][x] == PLAYER)
				game->player_count++;
			else if ((game->matrix[y][x] != EMPTY
				&& game->matrix[y][x] != WALL))
			{
				ft_printf("Invalid character: %c\n", game->matrix[y][x]);
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map_dimensions(t_game *game)
{
	int		y;
	size_t	x;

	y = 0;
	while (game->matrix[y] != NULL)
		y++;
	if (y < 3)
		return (-1);
	x = ft_strlen(game->matrix[0]);
	if (x < 3)
		return (-1);
	game->height = y;
	game->width = x;
	y = 0;
	while (game->matrix[y] != NULL)
	{
		if (ft_strlen(game->matrix[y]) != x)
			return (-1);
		y++;
	}
	return (0);
}

int	check_map_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)game->width)
	{
		if (game->matrix[0][x] != WALL
			|| game->matrix[game->height - 1][x] != WALL)
			return (-1);
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->matrix[y][0] != WALL
			|| game->matrix[y][game->width - 1] != WALL)
			return (-1);
		y++;
	}
	return (0);
}

int	map_validator(char *map_content, t_game *game)
{
	game->matrix = create_matrix(map_content);
	if (!game->matrix)
	{
		ft_printf("Failed to create matrix\n");
		return (-1);
	}
	if (check_map_dimensions(game) != 0)
	{
		ft_printf("Invalid map dimensions\n");
		return (-1);
	}
	if (check_map_walls(game) != 0)
	{
		ft_printf("Error\n Map is not enclosed by walls\n");
		return (-1);
	}
	if (count_map_elements(game) != 0)
	{
		return (-1);
	}
	if ((game->player_count != 1 || game->exit_count != 1
			|| game->collectible_count < 1))
	{
		ft_printf("Wrong elements count\n");
		return (-1);
	}
	if (path_validator(game) != 0)
	{
		ft_printf("No valid path\n");
		cleanup_game(game);
		return (-1);
	}
	return (0);
}
