/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:10:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/24 01:21:28 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int init_mlx_window(t_game *game)
{
	game->mlx_ptr = mlx_init(game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "cub3D", true);
	if (!game->mlx_ptr)
	{
		if (game->map.grid)
			ft_free_matrix(game->map.grid);
		game->map.grid = NULL;
		game->matrix = NULL;
		ft_printf("Error.\n Init window failed");
		return (-1);
	}
	return (0);
}

static int init_game(t_game *game, int argc, char **argv);

static int ends_with_cub(const char *filename)
{
	size_t len = ft_strlen(filename);
	if (len < 4)
		return 0;
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

static int init_game(t_game *game, int argc, char **argv)
{
	char *map_content;

	if (argc != 2)
	{
		ft_printf("Error\n Usage: ./cub3D <map.cub>\n");
		return (-1);
	}
	if (!ends_with_cub(argv[1]))
	{
		ft_printf("Error\n Map file must have .cub extension\n");
		return (-1);
	}
	map_content = open_and_read_map(argv[1]);
	if (!map_content)
		return (-1);
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
	t_game game;
	if (init_game(&game, argc, argv) == -1)
		return (1);
	mlx_key_hook(game.mlx_ptr, handle_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}