/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 02:09:55 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 02:10:00 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	destroy_textures(game);
	if (game->mlx_ptr)
	{
		mlx_terminate(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	game->screen = NULL;
	cleanup_map(&game->map, NULL);
	free(game);
}
