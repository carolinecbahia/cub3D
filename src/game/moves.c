/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:10:28 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/21 22:11:59 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	move_player(t_game *game, t_vectors *pos, int new_x, int new_y)
{
	char	dest;

	dest = game->matrix[new_y][new_x];
	if (dest == WALL)
		return (0);
	if (dest == COLLECTIBLE)
		game->collected++;
	if (dest == EXIT)
	{
		if (game->collected == game->collectible_count)
			check_win(game);
		return (0);
	}
	game->matrix[pos->y][pos->x] = EMPTY;
	game->matrix[new_y][new_x] = PLAYER;
	pos->x = new_x;
	pos->y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
	return (1);
}

int	handle_key(int keycode, t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	if (keycode == KEY_ESC)
		handle_close(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(game);
	if (keycode == KEY_A || keycode == KEY_LF)
		move_left(game);
	if (keycode == KEY_S || keycode == KEY_DW)
		move_down(game);
	if (keycode == KEY_D || keycode == KEY_RG)
		move_right(game);
	return (0);
}
