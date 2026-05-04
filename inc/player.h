/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:40:05 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/05 16:52:37 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"
# include "vector.h"

typedef struct	s_player
{
	mlx_image_t	*image;
	t_vector	pos;
}	t_player;


#endif
