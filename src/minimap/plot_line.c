/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:50:29 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/07 12:07:57 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	plot_line(mlx_image_t *img, t_point p0, t_point p1, uint32_t color)
{
	t_point		dist;
	t_vector	coord;
	int			steps;
	int			i;

	dist.x = p1.x - p0.x;
	dist.y = p1.y - p0.y;
	steps = fmax(abs(dist.x), abs(dist.y));
	coord.x = p0.x;
	coord.y = p0.y;
	i = 0;
	while (i <= steps)
	{
		mlx_put_pixel(img, round(coord.x), round(coord.y), color);
		coord.x += (double)dist.x / steps;
		coord.y += (double)dist.y / steps;
		i++;
	}
}
