/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:16 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/03 16:52:19 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

// Params
# define HEIGHT 1080
# define WIDTH 1920
# define BLOCK 50

// Colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RST "\033[0m"

// RGB COLORS
# define R 0xFF0000
# define G 0x00FF00
# define M 0xFF00FF
# define Y 0xFFFF00

//Keys
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

//
# define FAILURE 1
# define SUCCESS 0
# define MAP_ERR "Map not invalid."
#endif
