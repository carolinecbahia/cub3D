/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:05:39 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/11 12:08:16 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static double	get_row_distance(t_game *game, int y)
{
	double	camera_height;
	double	row;

	(void)game;
	camera_height = 0.5;
	row = (double)y - (double)HEIGHT / 2.0;
	return ((camera_height * (double)HEIGHT) / row);
}

static void	get_floor_ray_directions(t_game *game,
				double *ray_dir_x0, double *ray_dir_y0,
				double *ray_dir_x1, double *ray_dir_y1)
{
	*ray_dir_x0 = game->player.dir_x - game->player.plane_x;
	*ray_dir_y0 = game->player.dir_y - game->player.plane_y;
	*ray_dir_x1 = game->player.dir_x + game->player.plane_x;
	*ray_dir_y1 = game->player.dir_y + game->player.plane_y;
}

static uint32_t	get_floor_pixel(mlx_texture_t *texture, int x, int y)
{
	int			index;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	index = (y * texture->width + x) * 4;
	r = texture->pixels[index];
	g = texture->pixels[index + 1];
	b = texture->pixels[index + 2];
	a = texture->pixels[index + 3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static void	draw_floor_row(t_game *game, mlx_texture_t *texture,
				int y, double row_distance,
				double ray_dir_x0, double ray_dir_y0,
				double ray_dir_x1, double ray_dir_y1)
{
	int		x;
	int		tex_x;
	int		tex_y;
	double	floor_x;
	double	floor_y;
	double	floor_step_x;
	double	floor_step_y;

	floor_step_x = row_distance
		* (ray_dir_x1 - ray_dir_x0) / (double)WIDTH;
	floor_step_y = row_distance
		* (ray_dir_y1 - ray_dir_y0) / (double)WIDTH;

	floor_x = game->player.pos_x
		+ row_distance * ray_dir_x0;
	floor_y = game->player.pos_y
		+ row_distance * ray_dir_y0;

	x = 0;
	while (x < WIDTH)
	{
		tex_x = (int)((floor_x - floor(floor_x))
				* texture->width);
		tex_y = (int)((floor_y - floor(floor_y))
				* texture->height);

		if (tex_x >= (int)texture->width)
			tex_x = texture->width - 1;
		if (tex_y >= (int)texture->height)
			tex_y = texture->height - 1;

		put_pixel(game, x, y,
			get_floor_pixel(texture, tex_x, tex_y));

		floor_x += floor_step_x;
		floor_y += floor_step_y;
		x++;
	}
}

void	render_floor(t_game *game, mlx_texture_t *texture)
{
	int		y;
	double	row_distance;
	double	ray_dir_x0;
	double	ray_dir_y0;
	double	ray_dir_x1;
	double	ray_dir_y1;

	if (!texture)
		return;

	get_floor_ray_directions(game,
		&ray_dir_x0, &ray_dir_y0,
		&ray_dir_x1, &ray_dir_y1);

	y = HEIGHT / 2 + 1;
	while (y < HEIGHT)
	{
		row_distance = get_row_distance(game, y);
		draw_floor_row(game, texture, y, row_distance,
			ray_dir_x0, ray_dir_y0,
			ray_dir_x1, ray_dir_y1);
		y++;
	}
}
