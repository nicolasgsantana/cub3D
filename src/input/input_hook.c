/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:13:03 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/05 19:54:33 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	input_hook(void	*param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		printf("W key pressed delta: %f\n", mlx->delta_time);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		printf("A key pressed delta: %f\n", mlx->delta_time);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		printf("S key pressed delta: %f\n", mlx->delta_time);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		printf("D key pressed delta: %f\n", mlx->delta_time);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		printf("LEFT key pressed delta: %f\n", mlx->delta_time);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		printf("LEFT key pressed delta: %f\n", mlx->delta_time);
}
