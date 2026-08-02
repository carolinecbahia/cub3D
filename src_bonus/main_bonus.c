/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:58:46 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/02 04:18:32 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	free_fake_game(t_game *game)
{
	if (game)
	{
		if (game->mlx_ptr)
		{
			mlx_terminate(game->mlx_ptr);
		}
		free(game);
	}
}

void	init_mock_player_and_map(t_game *game)
{
	game->map.grid = malloc(sizeof(char *) * 6);
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
	t_game	*game;
	game = malloc(sizeof(t_game));
	if (!game)
		return (TRUE);
	game->mlx_ptr = NULL;
	game->screen = NULL;
	init_mock_player_and_map(game);
	game->map.ceiling_color = 0x3388FFFF;
	game->map.floor_color = 0x553311FF;
	if (init_mlx(game) == FAILURE)
	{
		free_fake_game(game);
		return (FALSE);
	}
    glfwSetInputMode(game->mlx_ptr->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	render_frame(game);
	mlx_key_hook(game->mlx_ptr, close_key_hook, game);
	mlx_close_hook(game->mlx_ptr, close_window_hook, game);
	mlx_cursor_hook(game->mlx_ptr, mouse_rotation_hook, game);
	mlx_loop_hook(game->mlx_ptr, update_game, game);
	mlx_loop(game->mlx_ptr);
	free_fake_game(game);
	return (0);
}
