/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:15:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/13 15:02:00 by anunes-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ========================================================================
** INCLUDES
** ======================================================================== */

# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //read, write, close
# include <fcntl.h> //open
# include <stdio.h> //perror
# include <string.h> //strerror
# include <math.h> //sin, cos, tan, sqrt, floor
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/inc/libft.h"
# include "types.h"

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
# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'

// Textures directions
#define TEX_NO 0
#define TEX_SO 1
#define TEX_WE 2
#define TEX_EA 3
#define TEX_COUNT 4

// Keycodes
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

/* Map Parsing and Validations */
int		check_file_extension(char *filename, char *extension);
int		open_file(char *filename);
char	**read_lines(char *filename);
int		validate_file(char *filename);

int		parse_texture_line(char *line, t_map *map);
int		valid_texture_line(char *line, char dir);
int		check_all_textures(t_map *map);

int		find_colors(char *line, char type);
int		parse_color_line(char *line, t_map *map);
int		parse_rgb(char *rgb_str, int *r, int *g, int *b);
int		validate_rgb(t_map *map);
int		check_all_colors(t_map *map);


int		validate_map_content(t_map *map);
int		validate_map_char(char c);
//int		flood_fill(t_game *game, t_map *map);
int		find_player(t_map *map, int *px, int *py, char *dir);
int		count_lines(int fd);
int		is_map_line(char *line);
int		is_empty_line(char	*line);
int		has_open_neighbor(t_map *map, int i, int j);
int		validate_borders(t_map	*map);
int		read_map_size(char **file_lines, int start, t_map *map);
int		find_map_start(char **file_lines);
int		fill_map_grid(char **file_lines, int start, t_map *map);
int		is_player(char c);

int		parse_file(char *filename, t_map *map);

/* Inits */
t_map	init_map(char *filename);

/* Utility functions */
int		create_grid(t_map *map);
char	**dup_grid(t_map *map);
void	ft_err(char *msg);
int		return_error(char *msg, int err);
void	ft_free_matrix(char **matrix);
void	cleanup_map(t_map	*map, char	**file_lines);

#endif