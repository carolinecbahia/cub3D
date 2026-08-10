/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 02:55:16 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/10 17:37:00 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_game *game)
{
	int			x;
	t_ray		ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(game, &ray, x);
		init_step_side(game, &ray);
		perform_dda(game, &ray);
		if (ray.side == 0)
			ray.perp_wall_dist = ray.side_dist_x - ray.delta_dist_x;
		else
			ray.perp_wall_dist = ray.side_dist_y - ray.delta_dist_y;
		draw_textured_column(game, &ray, x);
		x++;
	}
}
