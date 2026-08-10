/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 19:14:00 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/10 19:30:04 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	render_frame_bonus(t_game *game)
{
	render_ceiling_color(game);
	render_floor(game, game->floor_texture);
	raycasting(game);
	draw_debug_minimap(game);
}
