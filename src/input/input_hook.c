/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:13:03 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/06 15:13:41 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	input_hook(void	*param)
{
	t_game	*game;
	mlx_t	*mlx;

	game = param;
	mlx = game->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		game->player.pos.y -= MOVE_SPEED * mlx->delta_time;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		game->player.pos.x -= MOVE_SPEED * mlx->delta_time;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		game->player.pos.y += MOVE_SPEED * mlx->delta_time;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		game->player.pos.x += MOVE_SPEED * mlx->delta_time;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		printf("LEFT key pressed delta: %f\n", mlx->delta_time);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		printf("LEFT key pressed delta: %f\n", mlx->delta_time);
	}

}
