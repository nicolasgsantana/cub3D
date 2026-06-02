/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:20:50 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/01 21:53:55 by nde-sant         ###   ########.fr       */
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
	if (dda->side == 0)
		ray->wall_hit_x = game->player.pos.y + 
			(dda->side_dist_x - dda->delta_dist_x) * dda->ray_dir_y;
	else
		ray->wall_hit_x = game->player.pos.x + 
			(dda->side_dist_y - dda->delta_dist_y) * dda->ray_dir_x;
	ray->wall_hit_x -= floor(ray->wall_hit_x);
	ray->distance *= cos(normalize_angle(ray->angle - game->player.angle));
}

static mlx_texture_t	*get_wall_texture(t_game *game, t_dda *dda)
{
	if (dda->side == 0)
	{
		if (dda->step_x > 0)
			return (game->map.ea_tex);
		return (game->map.we_tex);
	}
	else
	{
		if (dda->step_y > 0)
			return (game->map.so_tex);
		return (game->map.no_tex);
	}
}

static void render_wall_slice(t_game *game, t_ray *ray, t_dda *dda, int col)
{
	mlx_texture_t	*tex;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
	uint32_t		color;
	uint8_t			*px;

	if (ray->distance <= 0.0001)
		ray->distance = 0.0001;
	line_h = (int)(WIN_HEIGHT / ray->distance);
	draw_start = (-line_h / 2) + (WIN_HEIGHT / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (line_h / 2) + (WIN_HEIGHT / 2);
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;

	tex = get_wall_texture(game, dda);

	// Which column of the texture
	tex_x = (int)(ray->wall_hit_x * tex->width);

	// Flip to avoid mirroring on certain faces
	if (dda->side == 0 && dda->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;

	// Vertical step through texture per screen pixel
	step = (double)tex->height / line_h;
	tex_pos = (draw_start - WIN_HEIGHT / 2 + line_h / 2) * step;

	while (draw_start <= draw_end)
	{
		tex_y = (int)tex_pos % tex->height;
		tex_pos += step;
		px = tex->pixels + (tex_y * tex->width + tex_x) * tex->bytes_per_pixel;
		color = (px[0] << 24) | (px[1] << 16) | (px[2] << 8) | px[3];
		mlx_put_pixel(game->scene_img, col, draw_start, color);
		draw_start++;
	}
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
		render_wall_slice(game, &ray, &dda, col);
		ray.angle = normalize_angle(ray.angle + angle_step);
		col++;
	}
}
