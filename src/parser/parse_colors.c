/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:48:18 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/11 23:37:35 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgba(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return (r << 24 | g << 16 | b << 8 | 255);
}

static int	valid_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i] || str[i] == '\n')
		return (0);
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	validate_rgb_array(char **rgb)
{
	int		r;
	int		g;
	int		b;

	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (ft_putendl_fd(COLOR_FORMAT_ERR, STDERR_FILENO), 1);
	if (!valid_nbr(rgb[0]) || !valid_nbr(rgb[1]) || !valid_nbr(rgb[2]))
		return (ft_putendl_fd(COLOR_NUMBER_ERR, STDERR_FILENO), 1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (ft_putendl_fd(RGB_RANGE_ERR, STDERR_FILENO), 1);
	return (0);
}

static int	set_color(char *line, uint32_t *color_ptr)
{
	char	**rgb;

	if (*color_ptr != 0)
		return (ft_putendl_fd(DUPLICATED_COLOR_ERR, STDERR_FILENO), 1);
	line++;
	rgb = ft_split(line, ',');
	if (validate_rgb_array(rgb))
		return (free_split(rgb), 1);
	*color_ptr = get_rgba(rgb);
	free_split(rgb);
	return (0);
}

int	parse_colors(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		if (set_color(line, &game->map.floor_color))
			return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		if (set_color(line, &game->map.ceiling_color))
			return (1);
	return (0);
}
