/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:26:34 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/10 17:51:42 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_vectors    calculate_tex_coords(t_game *game, t_ray *ray)
{
    t_vectors   tex;
    double      wall_x;

    if (ray->side == 0)
    {
        if (ray->raydir_x > 0)
            tex.x = TEX_EA;
        else
            tex.x = TEX_WE;
        wall_x = game->player.pos_y + ray->perp_wall_dist * ray->raydir_y;
    }
    else
    {
        if (ray->raydir_y > 0)
            tex.x = TEX_SO;
        else
            tex.x = TEX_NO;
        wall_x = game->player.pos_x + ray->perp_wall_dist * ray->raydir_x;
    }
    wall_x -= floor(wall_x);
    tex.y = (int)(wall_x * (double)game->textures[tex.x]->width);
    if ((ray->side == 0 && ray->raydir_x < 0)
        || (ray->side == 1 && ray->raydir_y > 0))
        tex.y = game->textures[tex.x]->width - tex.y - 1;
    return (tex);
}

static uint32_t	get_pixel_color(mlx_texture_t *texture, int x, int y, int side)
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
	if (side == 1)
	{
		r *= 0.7;
		g *= 0.7;
		b *= 0.7;
	}
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

// uint32_t	get_wall_color(t_ray *ray)
// {
// 	if (ray->side == 0)
// 	{
// 		if (ray->raydir_x > 0)
// 			return (0x888888FF);
// 		else
// 			return (0x666666FF);
// 	}
// 	else
// 	{
// 		if (ray->raydir_y > 0)
// 			return (0xAAAAAAFF);
// 		else
// 			return (0x555555FF);
// 	}
// }

// void	draw_vertical_line(t_game *game, int x,
// 		t_vectors limits, uint32_t color)
// {
// 	int	y;

// 	if (limits.x < 0)
// 		limits.x = 0;
// 	if (limits.y >= HEIGHT)
// 		limits.y = HEIGHT - 1;
// 	y = limits.x;
// 	while (y <= limits.y)
// 	{
// 		put_pixel(game, x, y, color);
// 		y++;
// 	}
// }

void	draw_textured_column(t_game *game, t_ray *ray, int x)
{
	int			line_height;
	t_vectors	limits;
	t_vectors	tex;
	double		step;
	double		tex_pos;
    
	line_height = (int)(HEIGHT / ray->perp_wall_dist);
	limits.x = -line_height / 2 + HEIGHT / 2;
	limits.y = line_height / 2 + HEIGHT / 2;
	tex = calculate_tex_coords(game, ray);
	step = 1.0 * game->textures[tex.x]->height / line_height;
	if (limits.x < 0)
        limits.x = 0;
	if (limits.y >= HEIGHT)
        limits.y = HEIGHT - 1;
	tex_pos = (limits.x - HEIGHT / 2 + line_height / 2) * step;
	while (limits.x <= limits.y)
	{
		put_pixel(game, x, limits.x, get_pixel_color(game->textures[tex.x],
				tex.y, (int)tex_pos & (game->textures[tex.x]->height - 1),
				ray->side));
		tex_pos += step;
		limits.x++;
	}
}
