/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:18:30 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 15:52:09 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_collision(t_game *game, double x, double y)
{
	double	buffer;

	buffer = 0.2;
	if (game->map.grid[(int)(y + buffer)][(int)(x + buffer)] == '1' ||
		game->map.grid[(int)(y - buffer)][(int)(x - buffer)] == '1' ||
		game->map.grid[(int)(y + buffer)][(int)(x - buffer)] == '1' ||
		game->map.grid[(int)(y - buffer)][(int)(x + buffer)] == '1')
	{
		return (TRUE);
	}
	return (FALSE);
}
