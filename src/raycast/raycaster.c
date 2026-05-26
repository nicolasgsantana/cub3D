/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:20:50 by alessandro        #+#    #+#             */
/*   Updated: 2026/05/25 21:15:37 by nde-sant         ###   ########.fr       */
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

static void	init_dda(t_game *game, t_ray *ray, t_dda *dda)
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

static void	perform_dda(t_game *game, t_ray *ray, t_dda *dda)
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
	ray->distance *= cos(normalize_angle(ray->angle - game->player.angle));
}

static void	render_wall_slice(t_game *game, t_ray *ray, int col)
{
	int			line_h;
	int			draw[2];
	uint32_t	color;

	if (ray->distance <= 0.0001)
		ray->distance = 0.0001;
	line_h = (int)(WIN_HEIGHT / ray->distance);
	draw[0] = (-line_h / 2) + (WIN_HEIGHT / 2);
	if (draw[0] <0)
		draw[0] = 0;
	draw[1] = (line_h / 2) + (WIN_HEIGHT / 2);
	if (draw[1] >= WIN_HEIGHT)
		draw[1] = WIN_HEIGHT - 1;
	if (ray->was_hit_vertical)
		color = 0x3498DBFF;
	else
		color = 0x2980B9FF;
	draw_wall_line(game, col, draw, color);
}

void	cast_rays(t_game *game)
{
	int		col;
	t_ray	ray;
	t_dda	dda;
	double	angle_step;

	angle_step = (FOV * DR) / WIN_WIDTH;
	ray.angle = normalize_angle(game->player.angle - ((FOV * DR) / 2));
	col = 0;
	while (col < WIN_WIDTH)
	{
		init_dda(game, &ray, &dda);
		perform_dda(game, &ray, &dda);
		render_wall_slice(game, &ray, col);
		ray.angle = normalize_angle(ray.angle + angle_step);
		col++;
	}
}
