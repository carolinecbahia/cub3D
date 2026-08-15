/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 02:55:16 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:24:14 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(game, &ray, x);
		init_delta_distance(&ray);
		init_step_side(game, &ray);
		if (perform_dda(game, &ray) == SUCCESS)
		{
			calculate_perp_distance(&ray);
			draw_textured_column(game, &ray, x);
		}
		x++;
	}
}
