/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:26 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/10 12:42:23 by mcatalan         ###   ########.fr       */
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

char	*clean_line(char *line, int i)
{
	int		f;
	char	*str;
	int		x;

	str = NULL;
	i = i + 2;
	x = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	f = i;
	while (line[f])
	{
		if (!ft_isspace(line[f]))
			f++;
		else
			break ;
	}
	str = malloc(sizeof(char) * (f - i + 1));
	if (!str)
		exit(1); //malloc error
	while (line[i] && f > i)
	{
		str[x] = line[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}

int	ft_isnum(char c)
{
	if (c >= 30 && c <= 39)
		return (0);
	return (1);
}

void	clear_line2(t_cube *cube, char *line, int pos_i)
{
	int		num;
	// char	*num_s;
	int		i;
	int		f;

	f = 0;
	i = 0;
	// num_s = NULL;
	(void)cube;
	num = 0;
	pos_i = pos_i + 1;
	while (line[pos_i])
	{
		if (ft_isspace(line[pos_i]))
			pos_i++;
		else
			break ;
	}
	printf("pos_i 2: %d\t%c\n", pos_i, line[pos_i]);
	while (line[pos_i])
	{
		if (ft_isnum(line[pos_i]) && i < 3)
		{
			f++;
			i++;
		}
		printf("esto es f: %d\n", f);
		pos_i++;
	}
	//ft_atoi
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
			cube->n_text = clean_line(cube->file[i], j);
		if (cube->file[i][j] == 'S')
			cube->s_text = clean_line(cube->file[i], j);
		if (cube->file[i][j] == 'W')
			cube->w_text = clean_line(cube->file[i], j);
		if (cube->file[i][j] == 'E')
			cube->e_text = clean_line(cube->file[i], j);
		if (cube->file[i][j] == 'F')
		{
			// printf("F: %sline: %d\npos: %d\n\n", cube->file[i], i, j);
			// clear_line2(cube, cube->file[i], j); //flag for pos
			// cube-> = ft_strdup(cube->file[i]);
			//TO_DO
		}
		if (cube->file[i][j] == 'C')
		{
			clear_line2(cube, cube->file[i], j);
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
