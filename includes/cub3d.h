/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:13 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/26 18:59:15 by mcatalan         ###   ########.fr       */
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
# include <string.h>
# include <math.h>

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

//game
//game.c
void	game(t_mlx_data *data, t_cube *cube);

//movement.c
void	print_stick(t_mlx_data *data, double line_len, int color);
void	my_pixel_put(t_img *img, int x, int y, int color);
int		print_player(t_mlx_data *data, int x, int y);
int		reset_buttons(int key, t_mlx_data *data);
void	rotate(t_mlx_data *data);
int		move(int key, t_mlx_data *data);
int		my_loop(t_mlx_data *data);

//rays.c
void	create_rays(t_mlx_data *data, t_cube *cube, int color);

//parsing
//parsing.c
int		checker_file(char *file);
int		parsing(t_cube *cube);

//utils
//prints.c
void	usage(void);
void	print_struct(t_cube *cube);
void	print_dp(char **file);
void	print_dp_no_enter(char **file);

//errors.c
void	malloc_err(int num);
void	generic_exit(char *str);

//frees.c
int		free_dp(char **dp);
int		free_all(t_cube *cube);
int		free_dp_int(int **dp);

// parsing
//parsing.c
int		parsing(t_cube *cube);

//get_info.c
int		get_info(t_cube *cube);

//checker_map.c
int		checker_map_extension(char *file);
int		checker_0(t_cube *cube, int i, int j);

//checker.c
int		checker_vals(t_cube *cube);
int		checker_map_extension(char *path);

//checker_utils.c
int		check_is_xpm_2(char *path);
int		update_pos_i(char *line, int pos_i, int flag);
void	extract_num(char *line, int pos_i, char *num_s);
void	flags(t_cube *cube, char flag, int i, char *num_s);

//parsing_utils.c
void	skip_sapaces(char *line, int *pos_i);
void	store_c_f_value(t_cube *cube, char *num_s, int i, int flag);
int		skip_init_spaces(char *line, int i);
int		find_word_end(char *line, int s);
char	*allocate_substring(char *line, int s, int f);

// map.c
void	map_parsing(t_cube *cube, int pos_map);

//map_utils.c
bool	get_ppos(t_cube *cube, int pos_map);
int		dir_player(char dir);
int		find_map_start(char **file, int pos_map);
bool	is_empty_line(char *line);
void	invalid_map(t_cube *cube);

#endif
