/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:26 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/07 13:03:02 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	checker_file(char *file) //To-Do
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

int	parsing(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->file[++i])
	{
		j = -1;
		while (cube->file[i][++j])
		{
			while (ft_isspace(cube->file[i][j]))
				j++;
			if (cube->file[i][j] == "N" && cube->file[i][j++] == "O")
				//is NO
			if (cube->file[i][j] == "S" && cube->file[i][j++] == "O")
				//is SO
			if (cube->file[i][j] == "W" && cube->file[i][j++] == "E")
				//is WE
			if (cube->file[i][j] == "E" && cube->file[i][j++] == "A")
				//is EA
		}
	}
	return (0);
}
