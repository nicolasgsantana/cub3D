/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:08:45 by nde-sant          #+#    #+#             */
/*   Updated: 2026/05/06 15:03:26 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>

# include "libft.h"
# include "MLX42.h"

# include "settings.h"

/* Dados mapa*/
typedef struct s_map
{
	char			**map_grid;
	int				width;
	int				height;
	/* Variável travada em 32bits para o RGBA compor uma cor
	cada letra precisa exatamente 8bits*/
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	/* Transforma os arquivos png após lindo pela mlx42
	eles são transformados em mlx_texture_t	*/
	mlx_texture_t	*no_tex; //textura norte
	mlx_texture_t	*so_tex; //textura sul
	mlx_texture_t	*ea_tex; // textura leste
	mlx_texture_t	*we_tex; // textura oeste

}				t_map;

/* Geometria e matriz*/
typedef struct s_point
{
	int				x;
	int				y;
}	t_point;

/* Raycasting */
typedef struct s_vector
{
	double			x;
	double			y;
}	t_vector;

typedef struct s_player
{
	t_vector		pos; // Posição
	t_vector		dir; // Direção (delta)
	double			angle; // Angulo atual
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*scene_img;
	t_map			map;
	t_player		player;
}	t_game;

/* Input */
void	input_hook(void *param);

/* Minimapa*/
void	render_minimap(t_game *game);
void	fill_block(t_game *game, t_point pos, int size, uint32_t color);
void	render_player(t_game *game);

/* Parser */
int		parse_cub(char *file, t_game *game);
int		check_extension(char *filename, char *extension);
int		parse_textures(char *line, t_game *game);
int		parse_color(char *line, t_game *game);
int		parse_grid(char *line, t_game *game);

/* utils/clean.c*/
void	free_split(char **split);
void	cleant_exit(t_game *game, int exit_code);
void	error_exit(char *msg, t_game *game);

/* Rendering */
void	render_hook(void *param);






#endif
