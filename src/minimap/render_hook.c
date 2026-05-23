/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:01:02 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/23 15:28:22 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_img(mlx_image_t *img)
{
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
}

void	render_hook(void *param)
{
	t_game	*game;

	game = param;
	clean_img(game->scene_img);
	cast_rays(game);
	render_minimap(&game->map, game->scene_img);
	render_player_2d(game, game->scene_img);
}
