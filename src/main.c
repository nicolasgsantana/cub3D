/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:15:02 by nde-sant          #+#    #+#             */
/*   Updated: 2026/04/29 18:11:20 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_minimap(t_map *map, mlx_image_t **img);

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map	map;

	map.map_grid = (char *[]){"111111111111", "100000000001", "100001100001", "100000000001", "100000000001", "111111111111"};
	map.height = 6;
	map.width = 12;
	mlx = mlx_init(640, 480, "cub3D", false);
	if (!mlx)
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, mlx->height / 3, mlx->height / 3);
	if (!img)
		return (EXIT_FAILURE);
	render_minimap(&map, &img);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
