/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:13 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/27 12:59:38 by mcatalan         ###   ########.fr       */
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

//utils
//prints.c
void	usage(void);
void	print_struct(t_cube *cube);
void	print_dp(char **file);

//errors.c
void	malloc_err(int num);

// parsing
//parsing.c
int		parsing(t_cube *cube);

//checker.c
int		checker_map_extension(char *file);
int		checker_vals(t_cube *cube);

// map.c
int		map_parsing(t_cube *cube, int pos_map);

#endif
