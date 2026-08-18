/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:42:37 by nde-sant          #+#    #+#             */
/*   Updated: 2026/08/18 13:18:55 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_M)
			toggle_mouse(param);
	}
}

void	toggle_mouse(t_game *game)
{
	game->mouse_active = !(game->mouse_active);
	if (game->mouse_active)
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
		mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	else
	{
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	}
}
