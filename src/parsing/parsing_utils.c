/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:22:31 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/29 12:23:32 by mcatalan         ###   ########.fr       */
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
