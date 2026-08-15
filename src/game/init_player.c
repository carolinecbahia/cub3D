/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 02:08:45 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 02:09:31 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	set_player_direction(t_player *player, char direction)
{
	if (direction == PLAYER_N)
	{
		player->dir_y = -1.0;
		player->plane_x = 0.66;
	}
	else if (direction == PLAYER_S)
	{
		player->dir_y = 1.0;
		player->plane_x = -0.66;
	}
	else if (direction == PLAYER_E)
	{
		player->dir_x = 1.0;
		player->plane_y = 0.66;
	}
	else if (direction == PLAYER_W)
	{
		player->dir_x = -1.0;
		player->plane_y = -0.66;
	}
	else
		return (FAILURE);
	return (SUCCESS);
}

int	init_player(t_game *game)
{
	if (!game)
		return (FAILURE);
	game->player.pos_x = game->map.player_x + 0.5;
	game->player.pos_y = game->map.player_y + 0.5;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
	game->player.mov_speed = 0.08;
	game->player.rot_speed = 0.05;
	return (set_player_direction(&game->player, game->map.player_dir));
}
