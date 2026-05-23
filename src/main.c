/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:15:02 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/21 19:58:15 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ---> INICIALIZAÇÂO DAS ESTRUTURAS ZERADAS <---
static void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->player.angle = 0.0;
	game->player.dir.x = 0.0;
	game->player.dir.y = 0.0;
}


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nUso correto: ./cub3D <caminho_do_mapa.cub>\n");
		return (EXIT_FAILURE);
	}
	init_game(&game);
	parse_cub(argv[1], &game);
	game.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	if (!game.mlx)
		error_exit("Failed to initialize MLX42", &game);
	game.scene_img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game.scene_img)
		error_exit("Failed to create scene image.", &game);
	render_minimap(&game.map, game.scene_img);
	mlx_image_to_window(game.mlx, game.scene_img, 0, 0);
	mlx_loop_hook(game.mlx, input_hook, &game);
	mlx_loop(game.mlx);
	clean_exit(&game, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
