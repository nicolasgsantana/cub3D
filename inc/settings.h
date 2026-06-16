/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:12:25 by nde-sant          #+#    #+#             */
/*   Updated: 2026/06/13 14:58:37 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

/*Cores do minimapa*/
# define MMAP_BG_COLOR	0x000000FF // Preto
# define MMAP_FG_COLOR	0xFFFFFFFF // Branco
# define PLAYER_COLOR	0xFF0000FF // vermelho

/* calculos matemáticos*/
# define PI 3.1415926535
# define MOVE_SPEED 1.0 // velocidade da caminhada
# define ROT_SPEED 1.0 // velocidade de rotação da camera
# define DR 0.0174533 // Graus para radianos
# define FOV 60 // Campo de visão
# define WALL_MARGIN 0.1

/* configurações tela*/
# define WIN_WIDTH 1024
# define WIN_HEIGHT 769

# define MOUSE_SENSITIVITY 0.05

#endif
