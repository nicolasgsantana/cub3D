/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:13:03 by nde-sant          #+#    #+#             */
/*   Updated: 2026/06/15 21:05:56 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall(t_game *game, double x, double y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)x;
	grid_y = (int)y;
	if (grid_y < 0 || grid_y >= game->map.height)
		return (1);
	if (grid_x < 0 ||
		grid_x >= (int)ft_strlen(game->map.map_grid[grid_y]))
		return (1);
	if (game->map.map_grid[grid_y][grid_x] == '1'
			|| game->map.map_grid[grid_y][grid_x] == ' ')
		return (1);
	return (0);
}
static void	handle_rotation(t_game *game)
{
	double	dt_time;
	int32_t	mouse_x;
	int32_t	mouse_y;
	int		delta_x;

	dt_time = game->mlx->delta_time;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player.angle -= ROT_SPEED * dt_time;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player.angle += ROT_SPEED * dt_time;
	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	delta_x = mouse_x - (WIN_WIDTH / 2);
	if(delta_x != 0)
	{
		game->player.angle += delta_x * MOUSE_SENSITIVITY * dt_time;
		mlx_set_mouse_pos(game->mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
	game->player.dir.x = cos(game->player.angle) * MOVE_SPEED;
	game->player.dir.y = sin(game->player.angle) * MOVE_SPEED;
}

static void	handle_movement_keys(t_game *game, double *dx, double *dy)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		*dx += cos(game->player.angle);
		*dy += sin(game->player.angle);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		*dx -= cos(game->player.angle);
		*dy -= sin(game->player.angle);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		*dx += cos(game->player.angle - (PI / 2));
		*dy += sin(game->player.angle - (PI / 2));
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		*dx += cos(game->player.angle + (PI / 2));
		*dy += sin(game->player.angle + (PI / 2));
	}
}

static void	handle_movement(t_game *game, double *new_x, double *new_y)
{
	double	dt_time;
	double	dx;
	double	dy;
	double	len;

	dt_time = game->mlx->delta_time;
	dx = 0;
	dy = 0;
	handle_movement_keys(game, &dx, &dy);
	len = sqrt(dx * dx + dy * dy);
	if (len > 0)
	{
		*new_x += (dx / len) * MOVE_SPEED * dt_time;
		*new_y += (dy / len) * MOVE_SPEED * dt_time;
	}
}

void	input_hook(void	*param)
{
	t_game	*game;
	double	new_x;
	double	new_y;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx,MLX_KEY_ESCAPE))
		clean_exit(game, EXIT_SUCCESS);
	new_x = game->player.pos.x;
	new_y = game->player.pos.y;
	handle_rotation(game);
	handle_movement(game, &new_x, &new_y);
	if (!is_wall(game, new_x + WALL_MARGIN, game->player.pos.y)
		&& !is_wall(game, new_x - WALL_MARGIN, game->player.pos.y))
		game->player.pos.x = new_x;
	if (!is_wall(game, game->player.pos.x, new_y + WALL_MARGIN)
		&& !is_wall(game, game->player.pos.x, new_y - WALL_MARGIN))
		game->player.pos.y = new_y;
}
