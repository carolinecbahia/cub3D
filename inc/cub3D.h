#include "../MLX42/include/MLX42/MLX42.h"
void handle_key(mlx_key_data_t keydata, void *param);

void ft_free_matrix(char **matrix);

char **create_matrix(char *map_content);

// ... outros protótipos ...

// Protótipo de path_validator deve vir após o typedef de t_game
void ft_err(char *msg);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:15:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/01/24 00:13:53 by ccavalca         ###   ########.fr       */
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
# include "../MLX42/include/MLX42/MLX42.h"
# include "types.h"
# include "../libft/inc/libft.h"

int path_validator(t_game *game);

void draw_map(t_game *game);

/* ========================================================================
** DEFINES & CONSTANTS
** ======================================================================== */

# define SUCCESS 0
# define FAILURE -1
# define TRUE 1
# define FALSE 0

# define TILE_SIZE 32

// Map characters
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'

// Keycodes (ajuste conforme sua lib ou sistema)
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LF 65361
# define KEY_DW 65364
# define KEY_RG 65363

/* ========================================================================
** FUNCTION PROTOTYPES
** ======================================================================== */

/* Initialization functions */

/* Core functions */


int check_file_extension(char *filename);
int read_file(t_map map);
int validate_file(t_map map);
t_map parse_map(t_map map);
int validate_texture_path(t_img img);
int parse_textures(t_img img);
int parse_colors(t_img img);
int validate_map_chars(t_map map);

int validate_walls(t_map map);
void find_player_pos(t_game *game, t_vectors *pos);
int check_map_borders(t_map map);
// int flood_fill(t_game game, t_map map);
int check_map_borders(t_map map);
int create_color(int r, int g, int b);
int validate_rgb(int rgb);

// Movimentação e utilidades
int move_up(t_game *game);
int move_down(t_game *game);
int move_left(t_game *game);
int move_right(t_game *game);
int handle_close(t_game *game);

/* Functions needed in main.c */
char *open_and_read_map(char *file);
int map_validator(char *map_content, t_game *game);
void cleanup_game(t_game *game);
void setup_game(t_game *game);

/* Utility functions */
int return_error(char *msg, int err);

#endif