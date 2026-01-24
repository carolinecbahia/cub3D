/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:10:28 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/24 01:21:28 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	move_player(t_game *game, t_vectors *pos, int new_x, int new_y)
{
	char dest;

	dest = game->matrix[new_y][new_x];
	if (dest == WALL)
		return (0);
	game->matrix[pos->y][pos->x] = EMPTY;
	game->matrix[new_y][new_x] = PLAYER;
	pos->x = new_x;
	pos->y = new_y;
	draw_map(game);
	return (1);
}

void handle_key(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;
	t_vectors pos;
	if (!game)
		return;
	find_player_pos(game, &pos);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		handle_close(game);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		move_up(game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		move_left(game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		move_down(game);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		move_right(game);
}
