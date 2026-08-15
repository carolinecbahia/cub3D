/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_sampling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 01:25:24 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:32:38 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static uint32_t	read_texture_pixel(mlx_texture_t *texture, int x, int y)
{
	int	index;

	index = (y * texture->width + x) * 4;
	return (((uint32_t)texture->pixels[index] << 24)
		| ((uint32_t)texture->pixels[index + 1] << 16)
		| ((uint32_t)texture->pixels[index + 2] << 8)
		| (uint32_t)texture->pixels[index + 3]);
}

static uint32_t	shade_color(uint32_t color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = ((color >> 24) & 0xFF) * 0.7;
	g = ((color >> 16) & 0xFF) * 0.7;
	b = ((color >> 8) & 0xFF) * 0.7;
	a = color & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

uint32_t	sample_texture(mlx_texture_t *texture, int x,
	double texture_pos, int side)
{
	uint32_t	color;
	int			y;

	if (!texture || !texture->pixels)
		return (0);
	if (x < 0 || x >= (int)texture->width || texture->height == 0)
		return (0);
	y = (int)texture_pos % texture->height;
	if (y < 0)
		y = 0;
	color = read_texture_pixel(texture, x, y);
	if (side == 1)
		color = shade_color(color);
	return (color);
}
