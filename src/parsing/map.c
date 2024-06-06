/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/06 10:48:14 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (false);
		line++;
	}
	return (true);
}

int	find_map_start(char **file, int pos_map)
{
	int		i;

	i = pos_map + 1;
	while (file[i] && is_empty_line(file[i]))
		i++;
	return (i);
}

int	dir_player(char dir)
{
	if (dir == 'N')
		return (1);
	else if (dir == 'S')
		return (2);
	else if (dir == 'W')
		return (3);
	else if (dir == 'E')
		return (4);
	return (-1);
}

bool	get_ppos(t_cube *cube, int pos_map)
{
	int	i;
	int	j;
	int	pc;

	pc = 0;
	i = pos_map - 1;
	while (cube->file[++i])
	{
		j = -1;
		while (cube->file[i][++j])
		{
			if (cube->file[i][j] == 'N' || cube->file[i][j] == 'S' || cube->file[i][j] == 'W' || cube->file[i][j] == 'E')
			{
				pc++;
				cube->player_x = i - pos_map;
				cube->player_y = j;
				cube->pos = dir_player(cube->file[i][j]);
				printf("pc = %d\tplayer_x = %d\tplayer_y = %d\n", pc, i - pos_map, j);
			}
		}
	}
	if (pc == 1)
		return (true);
	return (false);
}

// bool	check_one(char *line)
// {
// 	while (*line)
// 	{
// 		if (*line == '1')
// 			return (true);
// 		line++;
// 	}
// 	return (false);
// }

int	check_one(char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	printf("HOla3\n");
	while (str[i])
	{
		if (str[i] != '1')
			flag = 1;
		i++;
	}
	return (flag);
}

int	check_char(char c)
{
	if (c == '1')
		return (0);
	return (1);
}

void	invalid_map(t_cube *cube)
{
	printf("Error: invalid map\n");
	free_all(cube);
	exit(1);
}

void	check_margin(t_cube *cube, int pos_map)
{
	int	i;
	int	j;

	i = pos_map;
	printf("i: %d\n", i);
	printf("cube->map_h = %d\n", cube->map_h);
	printf("cube->map_w = %d\n", cube->map_w);
	while (i < cube->map_h)
	{
		j = 0;
		while (cube->file[i][j])
		{
			printf("j: %d\n", j);
			if (i == pos_map || i == (cube->map_w - 1))
			{
				printf("Entra\n");
				if (check_one(cube->file[i]))
				{
					printf("Entra2\n");
					invalid_map(cube);
				}
			}
			if (i == (cube->map_w - 1))
				if (check_one(cube->file[i]))
					invalid_map(cube);
			if (j == 0 || (j + 1) == ft_strlen(cube->map[i]))
				if (check_char(cube->map[i][j]))
					invalid_map(cube);
			j++;
		}
		i++;
	}
}

void	get_map_limits(t_cube *cube, int pos_map)
{
	int	i;
	int	j;

	i = pos_map;
	while (cube->file[++i])
	{
		j = -1;
		while (cube->file[i][++j])
		{
			if (j > cube->map_w)
				cube->map_w = j;
		}
	}
	cube->map_h = i - pos_map;
}

void	map_parsing(t_cube *cube, int pos_map)
{
	pos_map = find_map_start(cube->file, pos_map);
	if (!get_ppos(cube, pos_map))
		generic_exit("Check player on map. Not found or more than one.");
	get_map_limits(cube, pos_map);
	////  if (!is_closed(cube, pos_map))
	////   printf(RED"Error map\n"RST);
	////  get_dplayer(cube); // ultimo. get player direction.
	/// Julia repo
	check_margin(cube, pos_map);
	// check_playable(cube);
	print_struct(cube);
}
