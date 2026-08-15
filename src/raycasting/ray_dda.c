/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:14:28 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:23:38 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	advance_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static int	is_valid_position(t_game *game, t_ray *ray)
{
	if (!game || !game->map.grid)
		return (FALSE);
	if (ray->map_x < 0 || ray->map_y < 0)
		return (FALSE);
	if (ray->map_x >= game->map.width)
		return (FALSE);
	if (ray->map_y >= game->map.height)
		return (FALSE);
	if (!game->map.grid[ray->map_y])
		return (FALSE);
	return (TRUE);
}

int	perform_dda(t_game *game, t_ray *ray)
{
	char	cell;

	if (!game || !ray)
		return (FAILURE);
	ray->hit = FALSE;
	while (ray->hit == FALSE)
	{
		advance_ray(ray);
		if (!is_valid_position(game, ray))
			return (FAILURE);
		cell = game->map.grid[ray->map_y][ray->map_x];
		if (cell == WALL)
			ray->hit = TRUE;
		else if (cell != EMPTY)
			return (FAILURE);
	}
	return (SUCCESS);
}
