/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:28 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/28 12:00:02 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	checker_map_extension(char *path)
{
	size_t		path_len;
	size_t		ext_len;
	const char	*file_ext;

	path_len = 0;
	ext_len = 0;
	file_ext = NULL;
	path_len = ft_strlen(path);
	ext_len = ft_strlen(".cub");
	if (path_len >= ext_len)
	{
		file_ext = path + path_len - ext_len;
		if (ft_strcmp(file_ext, ".cub") == 0)
		{
			printf("SUCCESS\n");
			return (SUCCESS);
		}
	}
	return (FAILURE);
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
	//All vars has value + f & c are 
	if (check_total_vals(cube) != 6)
		generic_exit("Mapa no valores corrector o faltan. Floor o c"); //Eror msg
	//File ends .xpm && exists?
	if (check_xpm(cube))
		generic_exit("Files deben ser formato .xpm or wrong path"); //Err msg
	return (0);
}

