/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:10:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 02:19:20 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_game_data(t_game *game, char *filename)
{
	game->map = init_map(filename);
	if (!game->map.map_path)
		return (FAILURE);
	if (parse_file(filename, &game->map) == FAILURE)
		return (FAILURE);
	if (init_player(game) == FAILURE)
	{
		cleanup_map(&game->map, NULL);
		return (FAILURE);
	}
	game->running = TRUE;
	return (SUCCESS);
}

static void	run_game(t_game *game)
{
	render_frame(game);
	mlx_key_hook(game->mlx_ptr, close_key_hook, game);
	mlx_close_hook(game->mlx_ptr, close_window_hook, game);
	mlx_loop_hook(game->mlx_ptr, update_game, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (return_error("Usage: ./cub3D <map.cub>\n", 1));
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (return_error("Error\nAllocation failed\n", 1));
	if (init_game_data(game, argv[1]) == FAILURE)
	{
		free(game);
		return (1);
	}
	if (init_mlx(game) == FAILURE)
	{
		destroy_game(game);
		return (1);
	}
	run_game(game);
	destroy_game(game);
	return (0);
}
