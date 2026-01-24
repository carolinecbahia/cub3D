/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:51:57 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/24 01:05:35 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	count_map_elements(t_game *game)
{
	int	x;
	int	y;

	game->map.player_count = 0;
	y = 0;
	while (game->map.grid[y] != NULL)
	{
		x = 0;
		while (game->map.grid[y][x] != '\0')
		{
			if (game->map.grid[y][x] == PLAYER_N || game->map.grid[y][x] == PLAYER_S || game->map.grid[y][x] == PLAYER_E || game->map.grid[y][x] == PLAYER_W)
				game->map.player_count++;
			if ((game->map.grid[y][x] != EMPTY && game->map.grid[y][x] != WALL && game->map.grid[y][x] != PLAYER_N && game->map.grid[y][x] != PLAYER_S && game->map.grid[y][x] != PLAYER_E && game->map.grid[y][x] != PLAYER_W))
			{
				ft_printf("Invalid character: %c\n", game->map.grid[y][x]);
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}



int check_map_walls(t_game *game)
{
	int y;
	size_t len;

	// Checa primeira linha
	for (size_t x = 0; game->map.grid[0][x]; x++) {
		if (game->map.grid[0][x] != WALL) {
			ft_printf("[DEBUG] Falha na parede superior em x=%zu (char=%c)\n", x, game->map.grid[0][x]);
			return (-1);
		}
	}

	// Checa última linha
	y = 0;
	while (game->map.grid[y + 1])
		y++;
	for (size_t x = 0; game->map.grid[y][x]; x++) {
		if (game->map.grid[y][x] != WALL) {
			ft_printf("[DEBUG] Falha na parede inferior em x=%zu\n", x);
			return (-1);
		}
	}

	// Checa primeira e última coluna de cada linha
	for (int i = 0; game->map.grid[i]; i++) {
		len = ft_strlen(game->map.grid[i]);
		if (len == 0) {
			ft_printf("[DEBUG] Linha %d vazia\n", i);
			return (-1);
		}
		if (game->map.grid[i][0] != WALL) {
			ft_printf("[DEBUG] Falha na parede esquerda na linha %d\n", i);
			return (-1);
		}
		if (game->map.grid[i][len - 1] != WALL) {
			ft_printf("[DEBUG] Falha na parede direita na linha %d\n", i);
			return (-1);
		}
	}
	return (0);
}

int	map_validator(char *map_content, t_game *game)
{
	ft_printf("[DEBUG] Iniciando validação do mapa...\n");
	game->map.grid = create_matrix(map_content);
	if (!game->map.grid)
	{
		ft_printf("[DEBUG] Falha ao criar matriz do mapa\n");
		return (-1);
	}
	game->matrix = game->map.grid;
	// Atualiza altura do mapa
	int h = 0;
	while (game->map.grid[h]) h++;
	game->map.height = h;
	ft_printf("[DEBUG] Matriz criada. Altura: %d\n", game->map.height);
	for (int i = 0; i < game->map.height; i++)
		ft_printf("[DEBUG] Linha %d: '%s'\n", i, game->map.grid[i]);
	if (check_map_walls(game) != 0)
	{
		ft_printf("[DEBUG] Erro: mapa não está cercado por paredes\n");
		return (-1);
	}
	ft_printf("[DEBUG] Paredes externas OK\n");
	if (count_map_elements(game) != 0)
	{
		ft_printf("[DEBUG] Erro ao contar elementos do mapa\n");
		return (-1);
	}
	ft_printf("[DEBUG] Player count: %d\n", game->map.player_count);
	if (game->map.player_count != 1)
	{
		ft_printf("[DEBUG] Quantidade de players inválida: %d\n", game->map.player_count);
		return (-1);
	}
	ft_printf("[DEBUG] Player único OK\n");
	if (path_validator(game) != 0)
	{
		ft_printf("[DEBUG] Caminho inválido\n");
		cleanup_game(game);
		return (-1);
	}
	ft_printf("[DEBUG] Validação de mapa concluída com sucesso!\n");
	return (0);
}
