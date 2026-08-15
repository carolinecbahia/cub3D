/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anunes-o <anunes-o@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:15:29 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 13:58:41 by anunes-o         ###   ########.fr       */
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

// Raycasting
# define RAY_EPSILON 0.000001
# define RAY_INFINITY 1e30

/* ========================================================================
** FUNCTION PROTOTYPES
** ======================================================================== */

/* Map Parsing and Validations */
char		**read_lines(char *filename);
int			parse_texture_line(char *line, t_map *map);
int			valid_texture_line(char *line, char dir);
int			check_all_textures(t_map *map);
int			find_colors(char *line, char type);
int			parse_color_line(char *line, t_map *map);
int			parse_rgb(char *rgb_str, int *r, int *g, int *b);
int			check_all_colors(t_map *map);
int			count_lines(int fd);
int			is_map_line(char *line);
int			is_empty_line(char *line);
int			has_open_neighbor(t_map *map, int i, int j);
int			validate_borders(t_map *map);
int			read_map_size(char **file_lines, int start, t_map *map);
int			find_map_start(char **file_lines);
int			fill_map_grid(char **file_lines, int start, t_map *map);
int			is_player(char c);
int			parse_file(char *filename, t_map *map);
void		cleanup_map(t_map *map, char **file_lines);
int			parse_textures(char **file_lines, t_map *map);
int			parse_colors(char **file_lines, t_map *map);
int			parse_map(char **file_lines, t_map *map);
int			validate_file(char *filename);
int			validate_map_content(t_map *map);

/* Inits */
t_map		init_map(char *filename);
int			init_mlx(t_game *game);
int			init_player(t_game *game);

/* Rendering */
void		put_pixel(t_game *game, int x, int y, uint32_t color);
void		render_frame(t_game *game);
void		render_background(t_game *game);
int			load_all_textures(t_game *game);
void		destroy_textures(t_game *game);
void		draw_textured_column(t_game *game, t_ray *ray, int x);
int			select_texture(t_ray *ray);
int			calculate_texture_x(t_game *game, t_ray *ray, int texture_index);
uint32_t	sample_texture(mlx_texture_t *texture, int x,
				double texture_pos, int side);

/* Hooks*/
void		close_key_hook(mlx_key_data_t key, void *param);
void		close_window_hook(void *param);
void		update_game(void *param);
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		rotate_right(t_game *game);
void		rotate_left(t_game *game);
int			check_collision(t_game *game, double x, double y);

/* Raycasting*/
void		raycasting(t_game *game);
void		init_step_side(t_game *game, t_ray *ray);
void		init_ray(t_game *game, t_ray *ray, int x);
int			perform_dda(t_game *game, t_ray *ray);
void		init_delta_distance(t_ray *ray);
void		calculate_perp_distance(t_ray *ray);
int			check_file_extension(char *filename, char *extension);
int			open_file(char *filename);
int			validate_map_char(char c);
int			find_player(t_map *map, int *px, int *py, char *dir);

/* Utility functions */
int			create_grid(t_map *map);
char		**dup_grid(t_map *map);
void		ft_err(char *msg);
int			return_error(char *msg, int err);
void		ft_free_matrix(char **matrix);
void		destroy_game(t_game *game);

#endif