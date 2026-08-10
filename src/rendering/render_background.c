/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:18:51 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/10 19:19:55 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_ceiling_color(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(game, x, y, game->map.ceiling_color);
			x++;
		}
		y++;
	}
}

void	render_floor_color(t_game *game)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(game, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
}

void	render_background(t_game *game)
{
	render_ceiling_color(game);
	render_floor_color(game);
}
