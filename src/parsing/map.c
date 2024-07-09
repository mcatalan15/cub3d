/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/09 18:23:13 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	recursive(t_cube *cube, int x, int y, char **visited);

void	store_map(t_cube *cube, int pos_map)
{
	int	i;

	i = -1;
	cube->map = malloc(sizeof(char *) * (cube->map_h + 1));
	if (!cube->map)
		malloc_err(1);
	while (++i < cube->map_h)
	{
		cube->map[i] = ft_strdup(cube->file[i + pos_map]);
		if (!cube->map[i])
		{
			free(cube->map);
			malloc_err(1);
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

void	map_parsing(t_cube *cube, int pos_map)
{
	pos_map = find_map_start(cube->file, pos_map);
	if (!get_ppos(cube, pos_map))
		generic_exit("Check player on map. Not found or more than one.");
	get_map_limits(cube, pos_map);
	store_map(cube, pos_map);
	if (!is_valid_map(cube))
		invalid_map(cube);
}
