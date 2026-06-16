/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:41:34 by alessandro        #+#    #+#             */
/*   Updated: 2026/06/11 22:57:29 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"
/* liberar mtz. bi (map_grid ft_split)*/
void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clean_exit(t_game *game, int exit_code)
{
	if (!game)
		exit(exit_code);
	if (game->map.map_grid)
		free_split(game->map.map_grid);
	if(game->map.no_tex)
		mlx_delete_texture(game->map.no_tex);
	if(game->map.so_tex)
		mlx_delete_texture(game->map.so_tex);
	if(game->map.ea_tex)
		mlx_delete_texture(game->map.ea_tex);
	if(game->map.we_tex)
		mlx_delete_texture(game->map.we_tex);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(exit_code);
}

void	error_exit(char *msg, t_game *game)
{
	if (ft_strlen(msg) > 0)
		ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	clean_exit(game, EXIT_FAILURE);
}
