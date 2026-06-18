/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:39:57 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/18 17:59:55 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* retorna o caractere emuma posição (x,y)*/
static char	get_char(char **grid, int x, int y, int max_y)
{
	if (y < 0 || y >= max_y)
		return (' ');
	if (x < 0 || x >= (int)ft_strlen(grid[y]))
		return (' ');
	return (grid[y][x]);
}

/* Extrai as coordenadas iniciais e define para onde a câmera está olhando*/
static void	set_player_start(t_game *game, int x, int y, char dir)
{
	if (game->player.pos.x != 0.0)
		error_exit("Multiple players found in the file.", game);
	game->player.pos.x = x + 0.5;
	game->player.pos.y = y +0.5;
	if (dir == 'N')
		game->player.angle = 3 * PI / 2;
	else if (dir == 'S')
		game->player.angle = PI / 2;
	else if (dir == 'E')
		game->player.angle = 0.0;
	else if (dir == 'W')
		game->player.angle = PI;
	game->map.map_grid[y][x] = '0';
}

/*
	Analisa as regras de um caractere específico.
	Checa caracteres inválidos, define o jogador e
	verifica furos no chão.
*/
static void	check_map_char(t_game *game, int x, int y, char c)
{
	char	**g;
	int		h;

	g = game->map.map_grid;
	h = game->map.height;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		set_player_start(game, x, y, c);
		c = '0';
	}
	else if (c != '1' && c != '0' && c != ' ')
		error_exit("Invalid character found in the maze.", game);
	if (c == '0')
	{
		if (get_char(g, x, y -1, h) == ' '
			|| get_char(g, x, y + 1, h) == ' '
			|| get_char(g, x - 1, y, h) == ' '
			|| get_char(g, x + 1, y, h) == ' ')
			error_exit("Invalid map! The walls are not closed.", game);
	}
}

int	validate_map(t_game *game)
{
	int		x;
	int		y;
	char	**g;

	if (!game->map.map_grid)
		error_exit("No map found at the end of the .cub file.", game);
	g = game->map.map_grid;
	y = -1;
	while (g[++y])
	{
		x = -1;
		while (g[y][++x])
			check_map_char(game, x, y, g[y][x]);
	}
	if (game->player.pos.x == 0.0)
		error_exit("No player (N, S, E, W) was found.", game);
	if (!game->map.no_tex || !game->map.so_tex
		|| !game->map.ea_tex || !game->map.we_tex)
		error_exit("Missing texture(s) in the config file.", game);
	if (!game->map.floor_color || !game->map.ceiling_color)
		error_exit("Missing floor/ceiling color in configuration file.", game);
	return (1);
}
