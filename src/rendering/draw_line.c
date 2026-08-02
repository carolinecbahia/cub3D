/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:26:34 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/02 03:45:53 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint32_t	get_wall_color(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			return (0x888888FF);
		else
			return (0x666666FF);
	}
	else
	{
		if (ray->raydir_y > 0)
			return (0xAAAAAAFF);
		else
			return (0x555555FF);
	}
}

void	draw_vertical_line(t_game *game, int x,
		t_vectors limits, uint32_t color)
{
	int	y;

	if (limits.x < 0)
		limits.x = 0;
	if (limits.y >= HEIGHT)
		limits.y = HEIGHT - 1;
	y = limits.x;
	while (y <= limits.y)
	{
		put_pixel(game, x, y, color);
		y++;
	}
}
