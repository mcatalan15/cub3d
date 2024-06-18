/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:05:55 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/18 17:47:46 by mcatalan         ###   ########.fr       */
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
			return (SUCCESS);
	}
	return (FAILURE);
}

int	checker_0(t_cube *cube, int i, int j)
{
	if (cube->map[i][j + 1] == ' ')
		return (1);
	else if (cube->map[i][j - 1] == ' ')
		return (1);
	else if (cube->map[i + 1][j] == ' ')
		return (1);
	else if (cube->map[i - 1][j] == ' ')
		return (1);
	else if (j == (cube->map_w - 1) || j == 0)
		return (1);
	return (0);
}
