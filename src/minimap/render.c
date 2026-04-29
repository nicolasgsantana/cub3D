/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:52:50 by nde-sant          #+#    #+#             */
/*   Updated: 2026/04/29 17:40:35 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "settings.h"

void	fill_block(mlx_image_t **img, int posX, int posY, int wall)
{
	int	x;
	int	y;
	int	size;

	size = 16;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (wall)
				mlx_put_pixel(*img, (posX * size) + x,
					(posY * size) + y, MMAP_FG_COLOR);
			else
				mlx_put_pixel(*img, (posX * size) + x,
					(posY * size) + y, MMAP_BG_COLOR);
			x++;
		}
		y++;
	}
}

int	render_minimap(t_map *map, mlx_image_t **img)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (map->map_grid[row][col] == '0')
				fill_block(img, col, row, 0);
			else
				fill_block(img, col, row, 1);
			col++;
		}
		row++;
	}
	return (0);
}
