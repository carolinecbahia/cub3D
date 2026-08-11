/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:15:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/11 12:07:05 by ccavalca         ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 720

// Map characters
# define EMPTY '0'
# define WALL '1'
# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'

// Textures directions
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3

/* ========================================================================
** FUNCTION PROTOTYPES
** ======================================================================== */

/* Map Parsing and Validations */
int		check_file_extension(char *filename, char *extension);
int		open_file(char *filename);
void	read_lines(void);
int		validate_file(char *filename);
void	parse_texture_line(char **lines);
int		validate_texture_slot(char **slot, t_map *map, char dir);
int		validate_texture_path(t_map *map);
void	parse_color_line(char **lines);
int		validate_rgb(t_map *map);
int		validate_map(t_map *map);
int		validate_map_content(t_map *map);
int		validate_map_char(char c);
int		validate_walls(t_map *map);
void	find_player_pos(t_game *game, t_vectors *pos);
int		check_map_borders(t_map *map);
int		flood_fill(t_game *game, t_map *map);
int		build_map_row(char **grid, int i, char *line, int width);
void	find_player(t_map *map, int *px, int *py, char *dir);

/* Inits */
t_map	init_map(char *filename);
int		init_mlx(t_game *game);

/* Rendering */
void	put_pixel(t_game *game, int x, int y, uint32_t color);
void	render_frame(t_game *game);
void	render_ceiling_color(t_game *game);
void	render_floor_color(t_game *game);
void	render_background(t_game *game);
int     load_all_textures(t_game *game);
void    destroy_textures(t_game *game);
void	draw_textured_column(t_game *game, t_ray *ray, int x);
void	draw_debug_minimap(t_game *game);

/* Hooks*/
void	close_key_hook(mlx_key_data_t key, void *param);
void	close_window_hook(void *param);
void	update_game(void *param);
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);
int		check_collision(t_game *game, double x, double y);

/* Raycasting*/
void		raycasting(t_game *game);
void		init_step_side(t_game *game, t_ray *ray);
void        init_ray(t_game *game, t_ray *ray, int x);
void		perform_dda(t_game *game, t_ray *ray);
// uint32_t	get_wall_color(t_ray *ray);
// void	draw_vertical_line(t_game *game, int x, t_vectors limits, uint32_t color);

/* Utility functions */
char	**create_grid(t_map *map);
char	**dup_grid(t_map *map);
void	ft_err(char *msg);
int		return_error(char *msg, int err);
void	ft_free_matrix(char **matrix);

#endif