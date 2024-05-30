/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:28 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/30 11:05:37 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	check_c_f(int *arr)
{
	int	i;

	i = 0;
	while (i < 3 && arr[i] != -1)
		i++;
	if (i != 3)
		return (FAILURE);
	return (SUCCESS);
}

int	check_path_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (SUCCESS);
	}
	return (FAILURE);
}

int	check_xpm(t_cube *cube)
{
	int	i;

	i = 0;
	if (!check_is_xpm_2(cube->n_text) && !check_path_exist(cube->n_text))
		i++;
	if (!check_is_xpm_2(cube->s_text) && !check_path_exist(cube->s_text))
		i++;
	if (!check_is_xpm_2(cube->w_text) && !check_path_exist(cube->w_text))
		i++;
	if (!check_is_xpm_2(cube->e_text) && !check_path_exist(cube->e_text))
		i++;
	if (i == 4)
		return (SUCCESS);
	return (FAILURE);
}

int	check_total_vals(t_cube *cube)
{
	int	i;

	i = 0;
	if (cube->n_text)
		i++;
	if (cube->s_text)
		i++;
	if (cube->w_text)
		i++;
	if (cube->e_text)
		i++;
	if (!check_c_f(cube->f))
		i++;
	if (!check_c_f(cube->c))
		i++;
	return (i);
}

/*
	Check-totals + check if file ends .xpm and if the file exist
*/

int	checker_vals(t_cube *cube)
{
	if (check_total_vals(cube) != 6)
		generic_exit("Mapa no valores corrector o faltan. Floor o c");
	if (check_xpm(cube))
		generic_exit("Files deben ser formato .xpm or wrong path");
	return (0);
}
