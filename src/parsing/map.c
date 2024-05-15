/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/14 17:19:55 by mcatalan@st      ###   ########.fr       */
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

bool	check_map(t_cube *cube, int row)
{
	int		player_c;
	int		col;
	int		current_width;
	char	current_char;

	
	printf("player_c: %d\n", player_c);
	if (player_c != 1)
	{
		printf("entra\n");
		return (false);
	}
	return (true);
}

int	map_parsing(t_cube *cube, int pos_map)
{
	pos_map = find_map_start(cube->file, pos_map);
	check_map(cube, pos_map);
	// {
	// 	printf(RED"Error:\nInvalid map\n"RST);
	// 	exit (1); //invalid map error
	// }
	return (0);
}
