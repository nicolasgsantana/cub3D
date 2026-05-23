/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:48:18 by alessandro        #+#    #+#             */
/*   Updated: 2026/05/06 09:42:53 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
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

static uint32_t	parse_rgb_array(char **rgb, t_game *game)
{
	int		r;
	int		g;
	int		b;

	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_split(rgb);
		error_exit("Invalid color format. The correct format is: R,G,B.", game);
	}
	if (!valid_nbr(rgb[0]) || !valid_nbr(rgb[1]) || !valid_nbr(rgb[2]))
	{
		free_split(rgb);
		error_exit("The colors should only contain valid numbers.", game);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_split(rgb);
		error_exit("The RGB values ​​must be between 0 and 255.", game);
	}
	return (get_rgba(r, g, b, 255));
}

static void	set_color(char *line, uint32_t *color_ptr, t_game *game)
{
	char	**rgb;

	if (*color_ptr != 0)
		error_exit("Floor or ceiling color duplicated in the file.", game);
	line ++;
	rgb = ft_split(line, ',');
	*color_ptr = parse_rgb_array(rgb, game);
	free_split(rgb);

}

int	parse_colors(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		set_color(line, &game->map.floor_color, game);
	else if (ft_strncmp(line, "C ", 2) == 0)
		set_color(line, &game->map.ceiling_color, game);
	return (1);
}
