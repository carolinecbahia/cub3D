/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 01:25:37 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:29:57 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	select_texture(t_ray *ray)
{
	if (!ray)
		return (FAILURE);
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	if (ray->raydir_y > 0)
		return (TEX_NO);
	return (TEX_SO);
}

int	calculate_texture_x(t_game *game, t_ray *ray, int texture_index)
{
	mlx_texture_t	*texture;
	double			wall_x;
	int				texture_x;

	if (!game || !ray || texture_index < 0 || texture_index >= 4)
		return (FAILURE);
	texture = game->textures[texture_index];
	if (!texture || texture->width == 0)
		return (FAILURE);
	if (ray->side == 0)
		wall_x = game->player.pos_y
			+ ray->perp_wall_dist * ray->raydir_y;
	else
		wall_x = game->player.pos_x
			+ ray->perp_wall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->raydir_x > 0)
		|| (ray->side == 1 && ray->raydir_y < 0))
		texture_x = texture->width - texture_x - 1;
	if (texture_x < 0)
		texture_x = 0;
	if (texture_x >= (int)texture->width)
		texture_x = texture->width - 1;
	return (texture_x);
}
