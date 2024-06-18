/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:26 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/18 12:41:36 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || ft_isspace(c) == 1)
		return (true);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	else
		return (false);
}

void	checker_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (is_valid_char(cube->map[i][j]) == false)
				generic_exit("Map no correct chars");
		}
	}
}

char	*ft_strdup_fill_1(const char *s1, int width)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (width + 1));
	if (!str)
		malloc_err(1);
	while (i < width)
	{
		if (s1[i] != '1' && s1[i] != '0')
			str[i] = '1';
		else
			str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	copy_map(t_cube *cube)
{
	char	**map_cpy;
	int		i;

	i = -1;
	map_cpy = NULL;
	map_cpy = malloc(sizeof(char *) * (cube->map_h + 1));
	if (!map_cpy)
		malloc_err(1);
	while (cube->map[++i])
	{
		map_cpy[i] = ft_strdup_fill_1(cube->map[i], cube->map_w);
		if (!map_cpy[i])
		{
			free(map_cpy);
			malloc_err(1);
		}
	}
	map_cpy[i] = NULL;
	free_dp(cube->map);
	cube->map = map_cpy;
}

int	parsing(t_cube *cube)
{
	int	pos_map;

	pos_map = get_info(cube);
	checker_vals(cube);
	map_parsing(cube, pos_map);
	checker_map(cube);
	copy_map(cube);
	return (0);
}
