/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:20:50 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/06 16:44:27 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_wall_slice(t_game *game, t_ray *ray, t_dda *dda, int col)
{
	int				draw_start;
	int				draw_end;
	t_tex_slice		slice;
	uint32_t		color;
	uint8_t			*px;

	if (ray->distance <= 0.0001)
		ray->distance = 0.0001;
	draw_start = get_draw_start(ray);
	draw_end = get_draw_end(ray);
	init_tex_slice(&slice, game, ray, dda);
	while (draw_start <= draw_end)
	{
		slice.tex_y = (int)slice.tex_pos % slice.tex->height;
		slice.tex_pos += slice.step;
		px = slice.tex->pixels + (slice.tex_y * slice.tex->width + slice.tex_x)
			* slice.tex->bytes_per_pixel;
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
