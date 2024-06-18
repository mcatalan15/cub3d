/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/18 10:14:23 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	store_map(t_cube *cube, int pos_map)
{
	int	i;

	i = -1;
	cube->map = malloc(sizeof(char *) * (cube->map_h + 1));
	if (!cube->map)
		generic_exit("Error malloc"); //erro malloc
	while (++i < cube->map_h)
	{
		cube->map[i] = ft_strdup(cube->file[i + pos_map]);
		if (!cube->map[i])
		{
			free(cube->map);
			generic_exit("Error malloc"); //error malloc		
		}
	}
	
	cube->map[i] = NULL;
}

void	get_map_limits(t_cube *cube, int pos_map)
{
	int	i;
	int	j;

	i = pos_map;
	while (cube->file[++i] && is_empty_line(cube->file[i]) == false)
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

bool	check_ones(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != '1' && ft_isspace(str[i]) == 0)
			flag = 1;
	}
	if (flag == 1)
		return (false);
	return (true);
}

int	checker_0(t_cube *cube, int i, int j)
{

	if (cube->map[i][j + 1] == ' ')
		return (1);
	else if (cube->map[i][j - 1] == ' ')
		return (1);
	else if (cube->map[i + 1][j] == ' ')
		return (1);
	else if (cube->map[i - 1][j] == ' ')
		return (1);
	else if (j == (cube->map_w - 1) || j == 0)
		return (1);
	return (0);
}

bool	is_valid_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!check_ones(cube->map[0]) || !check_ones(cube->map[cube->map_h - 1]))
		generic_exit("Error map"); //check errors
	while (++i < (cube->map_h - 1))
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == '0')
			{
				if (checker_0(cube, i, j) == 1)
					generic_exit("map invalid"); // check errors
				j++;
			}
			else
				j++;
		}
	}
	return (true);
}

void	map_parsing(t_cube *cube, int pos_map)
{
	pos_map = find_map_start(cube->file, pos_map);
	if (!get_ppos(cube, pos_map))
		generic_exit("Check player on map. Not found or more than one."); //check error
	get_map_limits(cube, pos_map);
	store_map(cube, pos_map);
	if (!is_valid_map(cube))
		invalid_map(cube);
}
