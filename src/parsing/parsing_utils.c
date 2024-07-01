/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:22:31 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/01 18:33:47 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	skip_sapaces(char *line, int *pos_i)
{
	while (line[*pos_i] && ft_isspace(line[*pos_i]))
		(*pos_i)++;
}

void	store_c_f_value(t_cube *cube, char *num_s, int i, int flag)
{
	if (flag == 'c')
		cube->c[i] = ft_atoi(num_s);
	else
		cube->f[i] = ft_atoi(num_s);
}

int	skip_init_spaces(char *line, int i)
{
	while (line && ft_isspace(line[i]))
		i++;
	return (i);
}

int	find_word_end(char *line, int s)
{
	int	f;

	f = s;
	while (line[f])
	{
		if (!ft_isspace(line[f]))
			f++;
		else
			break ;
	}
	return (f);
}

char	*allocate_substring(char *line, int s, int f)
{
	char	*str;
	int		x;

	x = 0;
	str = malloc(sizeof(char) * (f - s + 3));
	if (!str)
		malloc_err(1);
	while (line[s] && f > s)
		str[x++] = line[s++];
	str[x] = '\0';
	return (str);
}
