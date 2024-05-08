/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:26 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/08 12:59:06 by mcatalan         ###   ########.fr       */
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

char	*clean_line(char *line, int pos)
{
	int		i;
	//int		j;
	char	*str;
	str = NULL;
	i = pos + 2;
	//j = 0;
	printf("pos primera letra: %d\n", pos);
	printf("I: %c\n", line[i]);
	while (line[++i])
	{
		while (ft_isspace(line[i]))
			i++;
	}
	printf("pos dps de spaces: %d\n", i);
	while (i < ft_strlen(line))
	{
		//str[j] = line[i];
		printf("%c",line[i]);
		i++;
	//	j++;
	}
	return (str);
	//return (line);
}

void	get_info(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->file[++i])
	{
		j = 0;
		while (ft_isspace(cube->file[i][j]))
			j++;
		if (cube->file[i][j] == 'N')
		{
			// printf("NO: %sline: %d\npos: %d\n\n", cube->file[i], i, j);
			// clean_and_save(cube, i, j, 1);
			cube->n_text = ft_strdup(clean_line(cube->file[i], j));
		}
		if (cube->file[i][j] == 'S')
		{
			// printf("SO: %sline: %d\npos: %d\n\n", cube->file[i], i, j);
			cube->s_text = ft_strdup(cube->file[i]);
		}
		if (cube->file[i][j] == 'W')
		{
			cube->w_text = ft_strdup(cube->file[i]);
		}
		if (cube->file[i][j] == 'E')
		{
			cube->e_text = ft_strdup(cube->file[i]);
		}
		if (cube->file[i][j] == 'F')
		{
			// printf("F: %sline: %d\npos: %d\n\n", cube->file[i], i, j);
			// cube->_text = ft_strdup(cube->file[i]);
			//TO_DO
		}
		if (cube->file[i][j] == 'C')
		{
			// printf("C: %sline: %d\npos: %d\n\n", cube->file[i], i, j);
			// cube->n_text = ft_strdup(cube->file[i]);
			//TO_DO
		}
	}
}

int	parsing(t_cube *cube)
{
	print_dp(cube->file);
	get_info(cube);
	print_struct(cube);
	return (0);
}
