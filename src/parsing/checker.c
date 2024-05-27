/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:28 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/27 13:05:13 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	checker_map_extension(char *file) //To-Do
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 4))
	{
		printf(RED "Error:\nInvalid file.\tNeeds .cub file\n" RST);
		return (1);
	}
	return (0);
}

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

int	check_is_xpm_2(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 4))
	{
		printf(RED "Error:\nInvalid file.\tNeeds .xpm file\n" RST);
		return (1);
	}
	return (SUCCESS);
}

int	check_is_xpm(t_cube *cube)
{
	int	i;

	i = 0;
	if (!check_is_xpm_2(cube->n_text))
		i++;
	if (!check_is_xpm_2(cube->s_text))
		i++;
	if (!check_is_xpm_2(cube->w_text))
		i++;
	if (!check_is_xpm_2(cube->e_text))
		i++;
	if (i == 4)
	{
		printf("success\n");
		return (SUCCESS);
	}
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

int	checker_vals(t_cube *cube)
{
	//Check has value
	if (check_total_vals(cube) != 6)
		printf(RED"Error:\n\tMapa no valores corrector. Floor o c \n"RST); //Eror msg
	//File ends .xpm
	if (check_is_xpm(cube))
		printf(RED"Error:\n\tFiles deben ser formato .xpm"RST);
	//File exist?
	return (0);
}

