/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:52:50 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/05 12:12:51 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	fill_block(mlx_image_t **img, t_map *map, t_point pos, int wall)
{
	int	x;
	int	y;
	int	size;

	size = (*img)->width / fmax(map->width, map->height);
	y = 1;
	while (y < size)
	{
		x = 1;
		while (x < size)
		{
			if (wall)
				mlx_put_pixel(*img, (pos.x * size) + x - 1,
					(pos.y * size) + y - 1, MMAP_FG_COLOR);
			else
				mlx_put_pixel(*img, (pos.x * size) + x - 1,
					(pos.y * size) + y - 1, MMAP_BG_COLOR);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_map *map, mlx_image_t **img)
{
	int			row;
	int			col;
	t_point		pos;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			pos.x = col;
			pos.y = row;
			if (map->map_grid[row][col] == '0')
				fill_block(img, map, pos, 0);
			else
				fill_block(img, map, pos, 1);
			col++;
		}
		row++;
	}
}
