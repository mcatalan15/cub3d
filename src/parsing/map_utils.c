/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:41:30 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/06/18 12:46:44 by mcatalan         ###   ########.fr       */
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
	int	i;

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
			if (cube->file[i][j] == 'N' || cube->file[i][j] == 'S'
				|| cube->file[i][j] == 'W' || cube->file[i][j] == 'E')
			{
				pc++;
				cube->player_x = i - pos_map;
				cube->player_y = j;
				cube->pos = dir_player(cube->file[i][j]);
			}
		}
	}
	if (pc == 1)
		return (true);
	return (false);
}

void	invalid_map(t_cube *cube)
{
	free_all(cube);
	generic_exit(MAP_ERR);
}
