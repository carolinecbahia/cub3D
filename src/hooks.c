/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:10:03 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/21 22:10:07 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	move_up(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x, pos.y - 1));
}

int	move_down(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x, pos.y + 1));
}

int	move_left(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x - 1, pos.y));
}

int	move_right(t_game *game)
{
	t_vectors	pos;

	find_player_pos(game, &pos);
	return (move_player(game, &pos, pos.x + 1, pos.y));
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_free_matrix(game->matrix);
#ifdef BONUS
	cleanup_game_bonus(game);
#else
	cleanup_game(game);
#endif
	exit (0);
}
