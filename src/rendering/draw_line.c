/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:26:34 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:29:31 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_column_limits(t_ray *ray, int x, t_column *column)
{
	if (!ray || ray->perp_wall_dist <= 0.0)
		return (FAILURE);
	column->screen_x = x;
	column->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	if (column->line_height <= 0)
		return (FAILURE);
	column->draw_start = -column->line_height / 2 + HEIGHT / 2;
	column->draw_end = column->line_height / 2 + HEIGHT / 2;
	if (column->draw_start < 0)
		column->draw_start = 0;
	if (column->draw_end >= HEIGHT)
		column->draw_end = HEIGHT - 1;
	return (SUCCESS);
}

static int	init_column_texture(t_game *game, t_ray *ray,
	t_column *column)
{
	mlx_texture_t	*texture;

	column->texture_index = select_texture(ray);
	if (column->texture_index == FAILURE)
		return (FAILURE);
	column->texture_x = calculate_texture_x(game, ray,
			column->texture_index);
	if (column->texture_x == FAILURE)
		return (FAILURE);
	texture = game->textures[column->texture_index];
	if (!texture || texture->height == 0)
		return (FAILURE);
	column->step = (double)texture->height / column->line_height;
	column->texture_pos = (column->draw_start - HEIGHT / 2
			+ column->line_height / 2) * column->step;
	return (SUCCESS);
}

static void	draw_column_pixels(t_game *game, t_ray *ray,
	t_column *column)
{
	mlx_texture_t	*texture;
	uint32_t		color;
	int				y;

	texture = game->textures[column->texture_index];
	y = column->draw_start;
	while (y <= column->draw_end)
	{
		color = sample_texture(texture, column->texture_x,
				column->texture_pos, ray->side);
		put_pixel(game, column->screen_x, y, color);
		column->texture_pos += column->step;
		y++;
	}
}

void	draw_textured_column(t_game *game, t_ray *ray, int x)
{
	t_column	column;

	if (init_column_limits(ray, x, &column) == FAILURE)
		return ;
	if (init_column_texture(game, ray, &column) == FAILURE)
		return ;
	draw_column_pixels(game, ray, &column);
}
