/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:34:36 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/06 16:44:48 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * PI);
	if (angle > 2 * PI)
		angle -= (2 * PI);
	return (angle);
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

int	get_draw_start(t_ray *ray)
{
	int	line_h;
	int	draw_start;

	line_h = (int)(WIN_HEIGHT / ray->distance);
	draw_start = (-line_h / 2) + (WIN_HEIGHT / 2);
	if (draw_start < 0)
		return (0);
	return (draw_start);
}

int	get_draw_end(t_ray *ray)
{
	int	line_h;
	int	draw_end;

	line_h = (int)(WIN_HEIGHT / ray->distance);
	draw_end = (line_h / 2) + (WIN_HEIGHT / 2);
	if (draw_end >= WIN_HEIGHT)
		return (WIN_HEIGHT - 1);
	return (draw_end);
}

void	init_tex_slice(t_tex_slice *slice, t_game *game, t_ray *ray,
							t_dda *dda)
{
	int	line_h;
	int	draw_start;

	line_h = (int)(WIN_HEIGHT / ray->distance);
	draw_start = get_draw_start(ray);
	slice->tex = get_wall_texture(game, dda);
	slice->tex_x = (int)(ray->wall_hit_x * slice->tex->width);
	if (dda->side == 0 && dda->ray_dir_x > 0)
		slice->tex_x = slice->tex->width - slice->tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_y < 0)
		slice->tex_x = slice->tex->width - slice->tex_x - 1;
	slice->step = (double)slice->tex->height / line_h;
	slice->tex_pos = (draw_start - WIN_HEIGHT / 2 + line_h / 2) * slice->step;
}
