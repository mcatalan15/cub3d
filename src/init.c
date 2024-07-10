/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:32:41 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/03 18:37:15 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	line_counter(char *file)
{
	int		fd;
	int		i;
	char	*aux;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	aux = get_next_line(fd);
	while (aux)
	{
		free(aux);
		aux = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	error_opening(void)
{
	perror("Error opening the file");
	return (1);
}

int	open_file(char *file, t_cube *cube)
{
	int		fd;
	char	*line;
	int		c_line;
	int		i;

	c_line = line_counter(file);
	cube->file = malloc(sizeof(char *) * (c_line + 1));
	if (!cube->file)
		malloc_err(1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_opening());
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		cube->file[++i] = line;
		line = get_next_line(fd);
	}
	cube->file[i + 1] = NULL;
	close(fd);
	return (0);
}

void	init(t_cube *cube)
{
	cube->map = NULL;
	cube->file = NULL;
	cube->n_text = NULL;
	cube->s_text = NULL;
	cube->w_text = NULL;
	cube->e_text = NULL;
	cube->f[0] = -1;
	cube->f[1] = -1;
	cube->f[2] = -1;
	cube->c[0] = -1;
	cube->c[1] = -1;
	cube->c[2] = -1;
	cube->pos = -1;
	cube->player_x = -1;
	cube->player_y = -1;
	cube->map_h = 0;
	cube->map_w = 0;
}
