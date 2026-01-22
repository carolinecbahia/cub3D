/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:10:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/21 22:11:22 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_mlx_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		free(game->matrix);
		ft_printf("Error.\n Init matrix failed");
		return (-1);
	}
	game->win_ptr = mlx_new_window(
			game->mlx_ptr,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"So Long");
	if (!game->win_ptr)
	{
		cleanup_game(game);
		ft_printf("Error.\n Init window failed");
		return (-1);
	}
	return (0);
}

static int	init_game(t_game *game, int argc, char **argv)
{
	char	*map_content;

	if (argc != 2)
	{
		ft_printf("Error\n Usage: ./so_long <map.ber>\n");
		return (-1);
	}
	map_content = open_and_read_map(argv[1]);
	if (!map_content)
	{
		return (-1);
	}
	if (map_validator(map_content, game) == -1)
	{
		free(map_content);
		return (-1);
	}
	free(map_content);
	if (init_mlx_window(game) == -1)
	{
		cleanup_game(game);
		return (-1);
	}
	setup_game(game);
	return (0);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
        return_error("Invalid arguments", 0);
    return (0);
}