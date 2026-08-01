/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:10:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 14:26:29 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (TRUE);
	game->mlx_ptr = NULL;
	game->screen = NULL;
	game->map.ceiling_color = 0x3388FFFF;
	game->map.floor_color = 0x553311FF;
	if (init_mlx(game) == FAILURE)
	{
		free_fake_game(game);
		return (FALSE);
	}
	render_frame(game);
	mlx_key_hook(game->mlx_ptr, close_key_hook, game);
	mlx_loop(game->mlx_ptr);
	free_fake_game(game);
	return (0);
}
