/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:34:36 by alessandro        #+#    #+#             */
/*   Updated: 2026/05/21 19:39:08 by alessandro       ###   ########.fr       */
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

void	draw_wall_line(t_game *game, int col, int *draw, uint32_t color)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < draw[0])
			mlx_put_pixel(game->scene_img, col, y, game->map.ceiling_color);
		else if (y <= draw[1])
			mlx_put_pixel(game->scene_img, col, y, color);
		else
			mlx_put_pixel(game->scene_img, col, y, game->map.floor_color);
		y++;
	}
}
