/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 13:29:19 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 15:25:44 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	close_window_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_close_window(game->mlx_ptr);
}
