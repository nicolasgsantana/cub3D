/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:30:30 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/18 18:01:33 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Verifica extensão do arquivo = .cub*/
int	check_extension(char *filename, char *extension)
{
	int	len_f;
	int	len_e;

	if (!filename || !extension)
		return (0);
	len_f = ft_strlen(filename);
	len_e = ft_strlen(extension);
	if (len_f < len_e)
		return (0);
	if (ft_strncmp(filename + len_f - len_e, extension, len_e) == 0)
		return (1);
	return (0);
}

/* Encaminha a linha lida para f. analisadora com base
 nos caracteres iniciais*/
static int	dispatch_line(char *line, t_game *game)
{
	char	*ptr;

	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (*ptr == '\n' || *ptr == '\0')
		return (0);
	if (game->map.map_grid != NULL)
	{
		if (*ptr != '1' && *ptr != '0')
			return (ft_putendl_fd(MAP_ORDER_ERR, STDERR_FILENO), 1);
		return (parse_grid(line, game), 0);
	}
	if (ft_strncmp(ptr, "NO ", 3) == 0 || ft_strncmp(ptr, "SO ", 3) == 0
		|| ft_strncmp(ptr, "WE ", 3) == 0 || ft_strncmp(ptr, "EA ", 3) == 0)
		return (parse_textures(ptr, game));
	else if (ft_strncmp(ptr, "F ", 2) == 0 || ft_strncmp(ptr, "C ", 2) == 0)
		return (parse_colors(ptr, game));
	else if (*ptr == '1' || *ptr == '0')
		return (parse_grid(line, game), 0);
	return (ft_putendl_fd(INVALID_CHAR_ERR, STDERR_FILENO), 1);
}

/* Faz abertura do arquivo e faz chama a dispatch para tratar
	o caracter que recebe*/
int	parse_cub(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		errors;

	if (!check_extension(file, ".cub"))
		error_exit("Invalid extension. The map must be a .cub file.", game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("The map file could not be opened.", game);
	errors = 0;
	line = get_next_line(fd);
	while (line)
	{
		errors += dispatch_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (errors > 0)
		error_exit("", game);
	validate_map(game);
	return (1);
}
