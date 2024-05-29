/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/29 11:51:57 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// bool	is_empty_line(char *line)
// {
// 	while (*line)
// 	{
// 		if (!ft_isspace(*line))
// 			return (false);
// 		line++;
// 	}
// 	return (true);
// }

// int	find_map_start(char **file, int pos_map)
// {
// 	int		i;

// 	i = pos_map + 1;
// 	while (file[i] && is_empty_line(file[i]))
// 		i++;
// 	return (i);
// }

// void	get_map_limits(t_cube *cube, int pos_map)
// {
// 	int		height;
// 	int		width;
// 	bool	in_map;
// 	int		i;

// 	height = 0;
// 	width = 0;
// 	in_map = false;
// 	i = pos_map - 1;
// 	while (cube->file[++i])
// 	{
// 		if (is_empty_line(cube->file[i]) && in_map)
// 			break ;
// 		if (!is_empty_line(cube->file[i]))
// 		{
// 			in_map = true;
// 			height++;
// 			width = ft_strlen(cube->file[i]);
// 			if (width > cube->map_w)
// 				cube->map_w = width;
// 		}
// 	}
// 	cube->map_h = height;
// }

// // bool	check_map(t_cube *cube, int row)
// // {
// // 	int		player_c;
// // 	int		col;
// // 	int		current_width;
// // 	char	current_char;

// // 	printf("player_c: %d\n", player_c);
// // 	if (player_c != 1)
// // 	{
// // 		printf("entra\n");
// // 		return (false);
// // 	}
// // 	return (true);
// // }

// bool	get_ppos(t_cube *cube, int pos_map)
// {
// 	int		i;
// 	int		j;

// 	i = pos_map - 1;
// 	while (cube->file[++i])
// 	{
// 		j = -1;
// 		while (cube->file[i][++j])
// 		{
// 			if (cube->file[i][j] == 'N' || cube->file[i][j] == 'S'
// 				|| cube->file[i][j] == 'W' || cube->file[i][j] == 'E')
// 			{
// 				if (cube->pos != -1)
// 					return (true);
// 				cube->pos = cube->file[i][j];
// 				cube->player_y = i - pos_map;
// 				cube->player_x = j;
// 			}
// 		}
// 	}
// 	return (false);
// }

// // bool	is_closed(t_cube *cube, int pos_map)
// // {
// // 	//verificar linea por linea que el borde esté cerrado
// // 	return (true); // El borde está completamente cerrado
// // }

// // int	map_parsing(t_cube *cube, int pos_map)
// // {
// // 	pos_map = find_map_start(cube->file, pos_map);
// // 	if (get_ppos(cube, pos_map)) //|| check_chars(cube, pos_map))
// -> TO-DO check spaces and invalid chars
// // 		printf(RED"Error map\n"RST);
// // 	get_map_limits(cube, pos_map);
// // 	if (!is_closed(cube, pos_map))
// // 		printf(RED"Error map\n"RST);
// // 	print_struct(cube);
// // 	return (0);
// // }
