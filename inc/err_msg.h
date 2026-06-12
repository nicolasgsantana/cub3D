/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-sant <nde-sant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:07:30 by nde-sant          #+#    #+#             */
/*   Updated: 2026/06/11 23:30:51 by nde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

# define DUPLICATE_TEXTURE_ERR "Duplicate texture in the configuration file."
# define FAILED_TEXTURE_LOAD_ERR "Failed to load texture. Check the PNG path."
# define TEXTURE_PATH_ERR "Missing or invalid texture path."
# define INVALID_CHAR_ERR "Invalid character found in configuration file."
# define MAP_ORDER_ERR "The map should be the last element!"
# define COLOR_FORMAT_ERR "Invalid color format. The correct format is: R,G,B."
# define COLOR_NUMBER_ERR "The colors should only contain valid numbers."
# define RGB_RANGE_ERR "The RGB values ​​must be between 0 and 255."
# define DUPLICATED_COLOR_ERR "Floor or ceiling color duplicated in the file."

#endif