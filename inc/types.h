/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:15:00 by ccavalca          #+#    #+#             */
/*   Updated: 2026/09/18 15:35:02 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/* ========================================================================
** STRUCTURES
** ======================================================================== */

typedef struct s_vectors
{
	int	x;
	int	y;
}	t_vectors;

typedef struct s_color
{
	int	rgba;
	int	present;
}	t_color;

typedef enum e_texture_type
{
	TEXTURE_NONE,
	TEXTURE_PNG,
	TEXTURE_XPM42
}	t_texture_type;

typedef struct s_wall_texture
{
	mlx_texture_t		*texture;
	xpm_t				*xpm;
	t_texture_type		type;
}	t_wall_texture;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	char	*map_path;
	char	*textures_path[4];
	t_color	floor_color;
	t_color	ceiling_color;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_map;

typedef struct s_flood
{
	t_map		*map;
	int			**visited;
	t_vectors	*stack;
	int			top;
}	t_flood;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	mov_speed;
	double	rot_speed;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_game
{
	mlx_t			*mlx_ptr;
	t_map			map;
	t_player		player;
	t_wall_texture	textures[4];	
	mlx_image_t		*screen;
	int				running;
}	t_game;

typedef struct s_column
{
	int		screen_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_index;
	int		texture_x;
	double	step;
	double	texture_pos;
}	t_column;

#endif
