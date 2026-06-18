/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:08:38 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/18 18:00:15 by nde-sant         ###   ########.fr       */
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
static int	load_texture(mlx_texture_t **texture, char *path)
{
	if (*texture != NULL)
	{
		free(path);
		return (ft_putendl_fd(DUPLICATE_TEXTURE_ERR, STDERR_FILENO), 1);
	}
	*texture = mlx_load_png(path);
	if (!*texture)
	{
		free(path);
		return (ft_putendl_fd(FAILED_TEXTURE_LOAD_ERR, STDERR_FILENO), 1);
	}
	free(path);
	return (0);
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
		return (ft_putendl_fd(TEXTURE_PATH_ERR, STDERR_FILENO), 1);
	}
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (load_texture(&game->map.no_tex, path));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (load_texture(&game->map.so_tex, path));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (load_texture(&game->map.we_tex, path));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (load_texture(&game->map.ea_tex, path));
	return (free(path), 0);
}
