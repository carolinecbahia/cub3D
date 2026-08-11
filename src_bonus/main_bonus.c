/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:13:30 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/11 12:28:14 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	free_fake_game_bonus(t_game *game, t_game_bonus *bonus)
{
	if (!game)
		return;
	if (bonus->floor_texture)
	{
		mlx_delete_texture(bonus->floor_texture);
		bonus->floor_texture = NULL;
	}
	destroy_textures(game);
	if (game->mlx_ptr)
	{
		mlx_terminate(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	free(game);
}

static void	init_mock_player_and_map(t_game *game)
{
	game->map.grid = malloc(sizeof(char *) * 6);
	if (!game->map.grid)
		return;
	game->map.grid[0] = ft_strdup("11111");
	game->map.grid[1] = ft_strdup("10101");
	game->map.grid[2] = ft_strdup("10001");
	game->map.grid[3] = ft_strdup("11001");
	game->map.grid[4] = ft_strdup("11111");
	game->map.grid[5] = NULL;
	game->map.width = 5;
	game->map.height = 5;
	game->player.pos_x = 2.5;
	game->player.pos_y = 2.5;
	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0.0;
	game->player.mov_speed = 0.08;
	game->player.rot_speed = 0.05;
}

int	main(void)
{
	t_game			*game;
	t_game_bonus	*bonus;
	mlx_texture_t	*floor_texture;

	game = ft_calloc(1, sizeof(t_game));
	bonus = ft_calloc(1, sizeof(t_game_bonus));
	if (!game || !bonus)
		return (EXIT_FAILURE);

	init_mock_player_and_map(game);
	bonus->game = game;

	game->map.ceiling_color = 0x3388FFFF;

	if (init_mlx(game) == FAILURE)
	{
		free_fake_game_bonus(game, bonus);
		return (EXIT_FAILURE);
	}

	floor_texture = mlx_load_png(
		"textures/bonus/floor/floor.png");
	if (!floor_texture)
	{
		free_fake_game_bonus(game, bonus);
		return (EXIT_FAILURE);
	}

	bonus->floor_texture = floor_texture;

	mlx_set_cursor_mode(game->mlx_ptr, MLX_MOUSE_DISABLED);

	render_frame_bonus(game, bonus);

	mlx_key_hook(game->mlx_ptr, close_key_hook, game);
	mlx_close_hook(game->mlx_ptr, close_window_hook, game);
	mlx_cursor_hook(game->mlx_ptr, mouse_rotation_hook, game);
	mlx_loop_hook(game->mlx_ptr, update_game_bonus, bonus);

	mlx_loop(game->mlx_ptr);

	free_fake_game_bonus(game, bonus);
	return (EXIT_SUCCESS);
}
