/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:18:30 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:16:35 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_blocked(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	if (!game || !game->map.grid)
		return (TRUE);
	if (x < 0.0 || y < 0.0)
		return (TRUE);
	if (x >= game->map.width || y >= game->map.height)
		return (TRUE);
	map_x = (int)x;
	map_y = (int)y;
	if (!game->map.grid[map_y])
		return (TRUE);
	if (game->map.grid[map_y][map_x] != EMPTY)
		return (TRUE);
	return (FALSE);
}

int	check_collision(t_game *game, double x, double y)
{
	double	buffer;

	buffer = 0.2;
	if (is_blocked(game, x + buffer, y + buffer)
		|| is_blocked(game, x - buffer, y - buffer)
		|| is_blocked(game, x - buffer, y + buffer)
		|| is_blocked(game, x + buffer, y - buffer))
		return (TRUE);
	return (FALSE);
}
