/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:52:50 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/06 14:42:34 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	fill_block(t_game *game, t_point pos, int size, uint32_t color)
{
	int			x;
	int			y;
	mlx_image_t	*img;

	img = game->scene_img;
	y = 1;
	while (y < size)
	{
		x = 1;
		while (x < size)
		{
			mlx_put_pixel(img, pos.x + x - 1,
				pos.y + y - 1, color);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_game *game)
{
	int			row;
	int			col;
	int			size;
	t_point		pos;

	size = WIN_WIDTH / fmax(game->map.width, game->map.height);
	row = 0;
	while (row < game->map.height)
	{
		col = 0;
		while (col < game->map.width)
		{
			pos.x = col * size;
			pos.y = row * size;
			if (game->map.map_grid[row][col] == '1')
				fill_block(game, pos, size, MMAP_FG_COLOR);
			else
				fill_block(game, pos, size, MMAP_BG_COLOR);
			col++;
		}
		row++;
	}
}
