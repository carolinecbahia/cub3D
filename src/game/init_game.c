/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:50:05 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:43:09 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	mlx_failure(t_game *game, char *message)
{
	if (message)
		ft_putstr_fd(message, 2);
	if (!game)
		return (FAILURE);
	destroy_textures(game);
	if (game->mlx_ptr)
	{
		mlx_terminate(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	game->screen = NULL;
	return (FAILURE);
}

int	init_image(t_game *game)
{
	game->screen = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->screen)
		return (mlx_failure(game, "Error\nImage creation failed\n"));
	if (mlx_image_to_window(game->mlx_ptr, game->screen, 0, 0) < 0)
		return (mlx_failure(game, "Error/nImage to window failed\n"));
	if (load_all_textures(game) == FAILURE)
		return (mlx_failure(game, NULL));
	return (SUCCESS);
}

int	init_mlx(t_game *game)
{
	if (!game)
		return (FAILURE);
	game->mlx_ptr = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx_ptr)
		return (mlx_failure(game, "Error\nInitialization failed\n"));
	if (init_image(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
