/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:47:24 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:36:07 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_frame(t_game *game)
{
	if (!game || !game->screen || !game->map.grid)
		return ;
	render_background(game);
	raycasting(game);
}
