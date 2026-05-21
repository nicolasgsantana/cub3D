/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:52:50 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/21 19:59:30 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_block(mlx_image_t *img, int size, t_point pos, uint32_t color)
{
	int	x;
	int	y;

	y = 0;
	while(y < size - 1)
	{
		x = 0;
		while (x < size - 1)
		{
			mlx_put_pixel(img, (pos.x * size) + x, (pos.y * size) + y, color);
			x++;
		}
		y++;
	}
}

static char	get_map_char(char * line, int col)
{
	if (col >= (int)ft_strlen(line))
		return (' ');
	return (line[col]);
}

void	render_minimap(t_map *map, mlx_image_t *img)
{
	int			row;
	int			col;
	t_point		pos;
	int			size;
	uint32_t	color;

	if (map->width > map->height)
		size = img->width / map->width;
	else
		size = img->width / map->height;
	row = -1;
	while(++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			pos.x = col;
			pos.y = row;
			if (get_map_char(map->map_grid[row], col) == '1')
				color = MMAP_FG_COLOR;
			else
				color = MMAP_BG_COLOR;
			fill_block(img, size, pos, color);
		}
	}
}

void	render_player_2d(t_game *game, mlx_image_t *img)
{
	int	size;
	int	px;
	int	py;
	int	i;
	int	j;

	if (game->map.width > game->map.height)
		size = img->width / game->map.width;
	else
		size = img->width / game->map.height;
	px = game->player.pos.x * size;
	py = game->player.pos.y * size;
	i = -3;
	while (i < 3)
	{
		j = -3;
		while (j < 3)
		{
			mlx_put_pixel(img, px + j, py + i, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}
