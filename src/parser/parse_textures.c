/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:08:38 by alessandro        #+#    #+#             */
/*   Updated: 2026/05/21 20:06:06 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* extrai o caminho do path */
static char	*get_texture_path(char *line)
{
	char	*path;
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	while (line[i] && (line[i] == ' ' || line [i] == '\t'))
		i++;
	path = ft_strdup(&line[i]);
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		if (path[i] == '\n')
			path[i] = '\0';
		i++;
	}
	return (path);
}
/* Carrega PNG e verifica se ja foi carregada */
static void	load_texture(mlx_texture_t **texture, char *path, t_game *game)
{
	if (*texture != NULL)
	{
		free(path);
		error_exit("Duplicate texture in the configuration file.", game);
	}
	*texture = mlx_load_png(path);
	if (!*texture)
	{
		free(path);
		error_exit("Failed to load texture. Check the PNG path.", game);
	}
	free(path);
}

/* Função chama pelo dispatch_line */
int	parse_textures(char *line, t_game *game)
{
	char	*path;

	path = get_texture_path(line);
	if (!path || path[0] == '\0')
	{
		if (path)
			free(path);
		error_exit ("Missing or invalid texture path.", game);
	}
	if (ft_strncmp(line, "NO ", 3) == 0)
		load_texture(&game->map.no_tex, path, game);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		load_texture(&game->map.so_tex, path, game);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		load_texture(&game->map.we_tex, path, game);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		load_texture(&game->map.ea_tex, path, game);
	return (1);
}
