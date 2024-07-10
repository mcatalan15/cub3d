/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:55:48 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/10 10:23:21 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

char	*clean_line(char *line, int i)
{
	char	*str;
	int		s;
	int		f;

	i += 2;
	s = skip_init_spaces(line, i);
	f = find_word_end(line, s);
	str = allocate_substring(line, s, f);
	if (!str)
		malloc_err(1);
	return (str);
}

void	parse_number(char *line, int *pos_i, char *num_s)
{
	int	x;

	x = 0;
	*pos_i = update_pos_i(line, *pos_i, 0);
	while (ft_isnum(line[*pos_i]) && line[*pos_i] && x < 3)
	{
		num_s[x] = line[*pos_i];
		(*pos_i)++;
		x++;
	}
	num_s[x] = '\0';
	*pos_i = update_pos_i(line, *pos_i, 2);
}

void	clean_line_f_c(t_cube *cube, char *line, int pos_i, char flag)
{
	char	*num_s;
	int		i;

	num_s = malloc(sizeof(char) * 4);
	if (!num_s)
		malloc_err(1);
	i = 0;
	pos_i = update_pos_i(line, pos_i + 1, 1);
	while (i < 3)
	{
		parse_number(line, &pos_i, num_s);
		flags(cube, flag, i, num_s);
		i++;
	}
	free(num_s);
}

int	get_info_others(t_cube *cube, int x, int j, int i)
{
	if (cube->file[i][j] == 'W' && cube->file[i][j + 1] == 'E')
	{
		cube->w_text = clean_line(cube->file[i], j);
		x++;
	}
	if (cube->file[i][j] == 'E' && cube->file[i][j + 1] == 'A')
	{
		cube->e_text = clean_line(cube->file[i], j);
		x++;
	}
	if (cube->file[i][j] == 'C')
	{
		clean_line_f_c(cube, cube->file[i], j, 'f');
		x++;
	}
	if (cube->file[i][j] == 'F')
	{
		clean_line_f_c(cube, cube->file[i], j, 'c');
		x++;
	}
	return (x);
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
		if (cube->file[i][j] == 'N' && cube->file[i][j + 1] == 'O')
		{
			cube->n_text = clean_line(cube->file[i], j);
			x++;
		}
		if (cube->file[i][j] == 'S' && cube->file[i][j + 1] == 'O')
		{
			cube->s_text = clean_line(cube->file[i], j);
			x++;
		}
		x = get_info_others(cube, x, j, i);
	}
	return (i);
}
