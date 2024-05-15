/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:13 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/14 11:09:37 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// external libs
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

//our libs
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"

//.h files
# include "definitions.h"
# include "structs.h"

//our .c functions by file
//init.c
void	init(t_cube *cube);
int		open_file(char *file, t_cube *cube);

//parsing.c
int		checker_file(char *file);
int		parsing(t_cube *cube);

//utils
//prints.c
void	usage(void);
void	print_struct(t_cube *cube);
void	print_dp(char **file);

//errors.c
void	malloc_err(int num);

// parsing
// map.c
int		map_parsing(t_cube *cube, int pos_map);

#endif
