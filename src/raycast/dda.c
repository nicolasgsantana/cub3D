/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 15:14:22 by nde-sant          #+#    #+#             */
/*   Updated: 2026/06/06 16:43:22 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_step_dist(t_game *game, t_dda *dda)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player.pos.x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - game->player.pos.x)
			* dda->delta_dist_x;
	}
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player.pos.y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - game->player.pos.y)
			* dda->delta_dist_y;
	}
}

void	init_dda(t_game *game, t_ray *ray, t_dda *dda)
{
	dda->map_x = (int)game->player.pos.x;
	dda->map_y = (int)game->player.pos.y;
	dda->ray_dir_x = cos(ray->angle);
	dda->ray_dir_y = sin(ray->angle);
	dda->delta_dist_x = fabs(1.0 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1.0 / dda->ray_dir_y);
	dda->hit = 0;
	init_step_dist(game, dda);
}

void	perform_dda(t_game *game, t_ray *ray, t_dda *dda)
{
	while (dda->hit == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (game->map.map_grid[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
	}
	if (dda->side == 0)
		ray->distance = (dda->side_dist_x - dda->delta_dist_x);
	else
		ray->distance = (dda->side_dist_y - dda->delta_dist_y);
	ray->was_hit_vertical = (dda->side == 0);
	if (dda->side == 0)
		ray->wall_hit_x = game->player.pos.y
			+ (dda->side_dist_x - dda->delta_dist_x) * dda->ray_dir_y;
	else
		ray->wall_hit_x = game->player.pos.x
			+ (dda->side_dist_y - dda->delta_dist_y) * dda->ray_dir_x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
	ray->distance *= cos(normalize_angle(ray->angle - game->player.angle));
}
