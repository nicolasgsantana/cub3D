/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:08:45 by nde-sant          #+#    #+#             */
/*   Updated: 2026/08/18 13:21:32 by nde-sant         ###   ########.fr       */
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
# include "err_msg.h"

typedef struct s_map
{
	char			**map_grid;
	int				width;
	int				height;
	uint32_t		floor_color;
	uint32_t		ceiling_color;
	mlx_texture_t	*no_tex;
	mlx_texture_t	*so_tex;
	mlx_texture_t	*ea_tex;
	mlx_texture_t	*we_tex;
}				t_map;

typedef struct s_point
{
	int				x;
	int				y;
}	t_point;

typedef struct s_vector
{
	double			x;
	double			y;
}	t_vector;

typedef struct s_ray
{
	double			angle;
	double			distance;
	double			wall_hit_x;
}	t_ray;

typedef struct s_dda
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
}	t_dda;

typedef struct s_tex_slice
{
	mlx_texture_t	*tex;
	int				tex_x;
	int				tex_y;
	double			tex_pos;
	double			step;
}	t_tex_slice;

typedef struct s_player
{
	t_vector		pos;
	t_vector		dir;
	double			angle;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*scene_img;
	t_map			map;
	t_player		player;
	bool			mouse_active;
}	t_game;

void	input_hook(void *param);
void	key_handler(mlx_key_data_t keydata, void *param);
void	toggle_mouse(t_game *game);

void	render_minimap(t_map *map, mlx_image_t *img);
void	render_player_2d(t_game *game, mlx_image_t *img);

int		parse_cub(char *file, t_game *game);
int		check_extension(char *filename, char *extension);
int		parse_textures(char *line, t_game *game);
int		parse_colors(char *line, t_game *game);
void	parse_grid(char *line, t_game *game);
int		validate_map(t_game *game);

double	normalize_angle(double angle);
void	init_tex_slice(t_tex_slice *slice, t_game *game, t_ray *ray,
			t_dda *dda);
int		get_draw_start(t_ray *ray);
int		get_draw_end(t_ray *ray);

void	cast_rays(t_game *game);

void	init_dda(t_game *game, t_ray *ray, t_dda *dda);
void	perform_dda(t_game *game, t_ray *ray, t_dda *dda);

void	free_split(char **split);
void	clean_exit(t_game *game, int exit_code);
void	error_exit(char *msg, t_game *game);

void	render_hook(void *param);
void	draw_background(t_game *game);

#endif
