/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:26 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/27 12:40:07 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*clean_line(char *line, int i)
{
	int		f;
	char	*str;
	int		x;

	str = NULL;
	i = i + 2;
	x = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	f = i;
	while (line[f])
	{
		if (!ft_isspace(line[f]))
			f++;
		else
			break ;
	}
	str = malloc(sizeof(char) * (f - i + 1));
	if (!str)
		exit(1); //malloc error
	while (line[i] && f > i)
	{
		str[x] = line[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}

void	clear_line2(t_cube *cube, char *line, int pos_i, char flag)
{
	char	*num_s;
	int		i;
	int		x;

	num_s = NULL;
	num_s = malloc(sizeof(char) * 4);
	if (!num_s)
		exit(1); // malloc error
	i = 0;
	x = 0;
	pos_i = pos_i + 1;
	while (line[pos_i])
	{
		if (ft_isspace(line[pos_i]))
			pos_i++;
		else
			break ;
	}
	while (i < 3)
	{
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
		if (flag == 'c')
			cube->c[i] = ft_atoi(num_s);
		else
			cube->f[i] = ft_atoi(num_s);
		i++;
	}
	free(num_s);
}

int	get_info(t_cube *cube)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	x = 0;
	while (cube->file[++i] && x <= 5)
	{
		j = 0;
		while (ft_isspace(cube->file[i][j]))
			j++;
		if (cube->file[i][j] == 'N')
		{
			cube->n_text = clean_line(cube->file[i], j);
			x++;
		}
		if (cube->file[i][j] == 'S')
		{
			cube->s_text = clean_line(cube->file[i], j);
			x++;
		}
		if (cube->file[i][j] == 'W')
		{
			cube->w_text = clean_line(cube->file[i], j);
			x++;
		}
		if (cube->file[i][j] == 'E')
		{
			cube->e_text = clean_line(cube->file[i], j);
			x++;
		}
		if (cube->file[i][j] == 'F')
		{
			clear_line2(cube, cube->file[i], j, 'f');
			x++;
		}
		if (cube->file[i][j] == 'C')
		{
			clear_line2(cube, cube->file[i], j, 'c');
			x++;
		}
	}
	return (i);
}

int	parsing(t_cube *cube)
{
	int	pos_map;

	pos_map = get_info(cube);
	checker_vals(cube);
	print_struct(cube);
	// map_parsing(cube, pos_map);
	return (0);
}
