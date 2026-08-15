/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 02:56:28 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/15 01:20:21 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_delta_distance(t_ray *ray)
{
	if (fabs(ray->raydir_x) < RAY_EPSILON)
		ray->delta_dist_x = RAY_INFINITY;
	else
		ray->delta_dist_x = fabs(1.0 / ray->raydir_x);
	if (fabs(ray->raydir_y) < RAY_EPSILON)
		ray->delta_dist_y = RAY_INFINITY;
	else
		ray->delta_dist_y = fabs(1.0 / ray->raydir_y);
}

void	calculate_perp_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x
			- ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y
			- ray->delta_dist_y;
	if (ray->perp_wall_dist < RAY_EPSILON)
		ray->perp_wall_dist = RAY_EPSILON;
}
