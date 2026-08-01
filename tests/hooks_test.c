/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:29:40 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 15:29:58 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D"

void	draw_square(t_game *game, int start_x, int start_y, int size, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel(game, start_x + x, start_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_debug_minimap(t_game *game)
{
	int	x;
	int	y;
	int	player_px_x;
	int	player_px_y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				draw_square(game, x * 16, y * 16, 16, 0xFFFFFFFF); // Parede Branca
			else
				draw_square(game, x * 16, y * 16, 16, 0x111111FF); // Chão Cinza escuro
			x++;
		}
		y++;
	}
	// Desenha o jogador (quadrado vermelho de 6x6 pixels)
	player_px_x = (int)(game->player.pos_x * 16);
	player_px_y = (int)(game->player.pos_y * 16);
	draw_square(game, player_px_x - 3, player_px_y - 3, 6, 0xFF0000FF);

	// Desenha um ponto verde à frente para mostrar para onde o jogador está olhando (rotação)
	int dir_px_x = (int)((game->player.pos_x + game->player.dir_x * 0.4) * 16);
	int dir_px_y = (int)((game->player.pos_y + game->player.dir_y * 0.4) * 16);
	draw_square(game, dir_px_x - 1, dir_px_y - 1, 3, 0x00FF00FF);
}