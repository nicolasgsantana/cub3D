/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aletude- <aletude-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:08:45 by nde-sant          #+#    #+#             */
/*   Updated: 2026/04/29 15:59:00 by aletude-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"

typedef struct s_map
{
	char		**map_grid;
	int			width;
	int			height;

	int			floor_color;
	int			ceiling_color;

	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;

/*	t_texture	north;
	t_texture	east;
	t_texture	west;
	t_texture	south; */
}				t_map;


#endif
