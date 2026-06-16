/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:23:28 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/14 18:05:13 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

static char	**append_to_grid(char **old, char *line, int rows, t_game *game)
{
	char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * (rows + 2));
	if (!new_grid)
		error_exit("Memory allocation error in the map array.", game);
	i = 0;
	while (i < rows)
	{
		new_grid[i] = old[i];
		i++;
	}
	new_grid[i] = ft_strdup(line);
	if (!new_grid[i])
		error_exit("Memory allocation error in the map array.", game);
	new_grid[i + 1] = NULL;
	if (old)
		free(old);
	return (new_grid);
}

void	parse_grid(char *line, t_game *game)
{
	int	rows;

	clean_newline(line);
	rows = 0;
	if (game->map.map_grid)
	{
		while (game->map.map_grid[rows])
			rows++;
	}
	game->map.map_grid = append_to_grid(game->map.map_grid, line, rows, game);
	game->map.height = rows + 1;
	if ((int)ft_strlen(line) > game->map.width)
		game->map.width = ft_strlen(line);
}
