/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:15:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/21 14:09:21 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ========================================================================
** INCLUDES
** ======================================================================== */

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include "types.h"
# include "libft.h"

/* ========================================================================
** DEFINES & CONSTANTS
** ======================================================================== */

# define SUCCESS 0
# define FAILURE -1
# define TRUE 1
# define FALSE 0

/* ========================================================================
** FUNCTION PROTOTYPES
** ======================================================================== */

/* Initialization functions */

/* Core functions */


/* Parsing functions */
int check_file_extension(t_map map);
int read_file(t_map map);
int validate_file(t_map map);
t_map parse_map(t_map map);
int validate_texture_path(t_img img);
int parse_textures(t_img img);
int parse_colors(t_img img);
int validate_map_chars(t_map map);
int validate_walls(t_map map);
t_player find_player_pos(t_player player);
int check_map_borders(t_map map);
int flood_fill(t_game game, t_map map);
int create_color(int r, int g, int b);
int validate_rgb(int rgb);

/* Utility functions */
int return_error(char *msg, int err);

#endif