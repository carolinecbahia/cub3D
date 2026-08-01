/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:02:02 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 15:23:32 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * game->player.mov_speed;
	new_y = game->player.pos_y + game->player.dir_y * game->player.mov_speed;
	if (!check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * game->player.mov_speed;
	new_y = game->player.pos_y - game->player.dir_y * game->player.mov_speed;
	if (!check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * game->player.mov_speed;
	new_y = game->player.pos_y - game->player.dir_x * game->player.mov_speed;
	if (!check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * game->player.mov_speed;
	new_y = game->player.pos_y + game->player.dir_x * game->player.mov_speed;
	if (!check_collision(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!check_collision(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}
