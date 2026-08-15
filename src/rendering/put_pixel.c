/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:16:21 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 13:39:17 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(t_game *game, int x, int y, uint32_t color)
{
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
		mlx_put_pixel(game->screen, x, y, color);
}
