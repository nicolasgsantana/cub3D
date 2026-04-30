/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:15:02 by nde-sant          #+#    #+#             */
/*   Updated: 2026/04/30 11:32:17 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	render_minimap(t_map *map, mlx_image_t **img);

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*map_img;
	t_map	map;

	map.map_grid = (char *[]){"111111111111", "100000000001", "100001100001", "100000000001", "100000000001", "111111111111"};
	map.height = 6;
	map.width = 12;
	mlx = mlx_init(640, 480, "cub3D", false);
	if (!mlx)
		return (EXIT_FAILURE);
	map_img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!map_img)
		return (EXIT_FAILURE);
	render_minimap(&map, &map_img);
	mlx_image_to_window(mlx, map_img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
