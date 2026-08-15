/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:50:05 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/14 02:22:12 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_image(t_game *game)
{
	game->screen = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->screen)
	{
		mlx_terminate(game->mlx_ptr);
		game->mlx_ptr = NULL;
		ft_putstr_fd("Error\nImage creation failed\n", 2);
		return (FAILURE);
	}
	if (mlx_image_to_window(game->mlx_ptr, game->screen, 0, 0) < 0)
	{
		mlx_terminate(game->mlx_ptr);
		game->mlx_ptr = NULL;
		ft_putstr_fd("Error\nImage to window failed\n", 2);
		return (FAILURE);
	}
	if (load_all_textures(game) == FAILURE)
	{
		mlx_terminate(game->mlx_ptr);
		destroy_textures(game);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx_ptr)
	{
		ft_putstr_fd("Error.\n MLX init failed", 0);
		return (FAILURE);
	}
	if (init_image(game) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
