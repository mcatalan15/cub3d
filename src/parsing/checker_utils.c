/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:59:17 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/03 18:39:02 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

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

void	flags(t_cube *cube, char flag, int i, char *num_s)
{
	if (flag == 'c')
		cube->f[i] = ft_atoi(num_s);
	else
		cube->c[i] = ft_atoi(num_s);
}

void	extract_num(char *line, int pos_i, char *num_s)
{
	int	x;

	x = 0;
	while (line[pos_i] && ft_isspace(line[pos_i]))
		pos_i++;
	while (ft_isnum(line[pos_i]) && line[pos_i] && x < 3)
	{
		num_s[x] = line[pos_i];
		pos_i++;
		x++;
	}
	if (line[pos_i] == ',')
		pos_i++;
	num_s[x] = '\0';
}

int	update_pos_i(char *line, int pos_i, int flag)
{
	if (flag == 1)
	{
		while (line[pos_i])
		{
			if (ft_isspace(line[pos_i]))
				pos_i++;
			else
				break ;
		}
	}
	else if (flag == 0)
	{
		while (line[pos_i] && ft_isspace(line[pos_i]))
			pos_i++;
	}
	else
	{
		if (line[pos_i] == ',')
			pos_i++;
	}
	return (pos_i);
}

int	check_is_xpm_2(char *path)
{
	size_t		path_len;
	size_t		ext_len;
	const char	*file_ext;

	path_len = 0;
	ext_len = 0;
	file_ext = NULL;
	path_len = ft_strlen(path);
	ext_len = ft_strlen(".xpm");
	if (path_len >= ext_len)
	{
		file_ext = path + path_len - ext_len;
		if (ft_strcmp(file_ext, ".xpm") == 0)
			return (SUCCESS);
	}
	return (FAILURE);
}
