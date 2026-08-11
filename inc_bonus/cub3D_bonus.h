/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 18:01:51 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/11 12:28:33 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/* ========================================================================
** INCLUDES
** ======================================================================== */

# include "cub3D.h"
# include "types_bonus.h"
# include <GLFW/glfw3.h>

/* ========================================================================
** DEFINES & CONSTANTS
** ======================================================================== */

/* ========================================================================
** FUNCTION PROTOTYPES
** ======================================================================== */

/* Hooks */
void	mouse_rotation_hook(double xpos, double ypos, void *param);

/* Rendering */
void	render_floor(t_game *game, mlx_texture_t *texture);
void	render_frame_bonus(t_game *game, t_game_bonus *bonus);

/* Game */
void	update_game_bonus(void *param);

#endif