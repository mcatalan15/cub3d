/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul-kr <jpaul-kr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:28 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/04 12:36:41 by jpaul-kr         ###   ########.fr       */
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
		generic_exit("Map values not valid. Check F or C");
	if (check_xpm(cube))
		generic_exit("Files not found or must be in a .xpm format");
	return (0);
}
