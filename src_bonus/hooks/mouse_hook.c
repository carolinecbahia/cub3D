/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:58:13 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/02 04:16:42 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	mouse_rotation_hook(double xpos, double ypos, void *param)
{
	t_game			*game;
	static double	last_x = -1.0;
	double			delta_x;
	double			angle;
	double			old_dir_x;
	double			old_plane_x;

    (void)ypos;
	game = (t_game *)param;
	if (last_x < 0)
	{
		last_x = xpos;
		return ;
	}
	delta_x = xpos - last_x;
	last_x = xpos;
	angle = delta_x * 0.003;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle) - game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y * cos(angle);
}
