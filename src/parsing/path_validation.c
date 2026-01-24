/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:55:59 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/24 00:45:45 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	find_player_pos(t_game *game, t_vectors *pos)
{
	int	x;
	int	y;

	y = 0;
	while (game->matrix[y])
	{
		x = 0;
		while (game->matrix[y][x])
		{
			if (game->matrix[y][x] == PLAYER)
			{
				pos->x = x;
				pos->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}







int	path_validator(t_game *map_data)
{
	t_vectors	player_pos;

	find_player_pos(map_data, &player_pos);
	// Aqui você pode adicionar validação de bordas e player
	if (check_map_borders(map_data->map) != 0)
		return (-1);
	// Exemplo: checar se player_pos.x/y são válidos
	return (0);
}
