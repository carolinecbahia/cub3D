/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:27:31 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/11 12:30:21 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	update_game_bonus(void *param)
{
	t_game_bonus	*bonus;
	t_game		*game;

	bonus = (t_game_bonus *)param;
	game = bonus->game;
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_W))
		move_forward(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_S))
		move_backward(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_LEFT))
		rotate_left(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_RIGHT))
		rotate_right(game);
	render_frame_bonus(game, bonus);
}
