/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:50:05 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 13:50:48 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx_ptr)
	{
		ft_putstr_fd("Error.\n MLX init failed", 0);
		return (FAILURE);
	}
	game->screen = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->screen)
	{
		mlx_terminate(game->mlx_ptr);
		ft_putstr_fd("Error\nImage creation failed\n", 2);
		return (FAILURE);
	}
	if (mlx_image_to_window(game->mlx_ptr, game->screen, 0, 0) < 0)
	{
		mlx_terminate(game->mlx_ptr);
		ft_putstr_fd("Error\nImage to window failed\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}
