/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:02:17 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 15:51:45 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
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
	render_frame(game);
}
