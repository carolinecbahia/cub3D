/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 02:55:16 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/02 03:47:12 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_game *game)
{
	int			x;
	t_ray		ray;
	int			line_height;
	t_vectors	limits;

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
		line_height = (int)(HEIGHT / ray.perp_wall_dist);
		limits.x = -line_height / 2 + HEIGHT / 2;
		limits.y = line_height / 2 + HEIGHT / 2;
		draw_vertical_line(game, x, limits, get_wall_color(&ray));
		x++;
	}
}
