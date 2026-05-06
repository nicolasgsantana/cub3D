/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:51:42 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/06 14:45:37 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(t_game *game)
{
	int		block_size;
	int		player_size;
	t_point	pos;

	block_size = WIN_WIDTH / fmax(game->map.width, game->map.height);
	player_size = block_size / 4;
	pos.x = game->player.pos.x * block_size;
	pos.y = game->player.pos.y * block_size;
	fill_block(game, pos, player_size, PLAYER_COLOR);
}
