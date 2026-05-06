/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:15:02 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/06 15:04:25 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_game		game;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		map;
	t_player	player;

	// init test map
	map.map_grid = (char *[]){	"111111111111",
								"100000000001",
								"100001100001",
								"10000N000001",
								"100000000001",
								"111111111111"};
	map.height = 6;
	map.width = 12;
	// init mlx
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	if (!mlx)
		return (EXIT_FAILURE);
	// init scene img
	img = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!img)
		return (EXIT_FAILURE);
	// init player
	player.angle = 0;
	player.pos.x = 5.5;
	player.pos.y = 3.5;
	//init game
	game.mlx = mlx;
	game.scene_img = img;
	game.map = map;
	game.player = player;
	//draw
	mlx_image_to_window(mlx, img, 0, 0);
	//hooks
	mlx_loop_hook(mlx, render_hook, &game);
	mlx_loop_hook(mlx, input_hook, &game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
