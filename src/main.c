/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/07 11:58:18 by mcatalan         ###   ########.fr       */
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
	if (fd ==  -1)
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

int	open_file(char *file, t_cube *cube)
{
	int		fd;
	char	*line;
	int		c_line;
	int		i;

	c_line = line_counter(file);
	cube->file = malloc(sizeof(char *) * (c_line + 1));
	if (!cube->file)
		exit (1);//error_malloc
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}
	i = -1;
	while ((line = get_next_line(fd)) != NULL)
		cube->file[++i] = line;
	cube->file[i + 1] = NULL;
	close(fd);
	return (0);
}

int	cub3d(char *str)
{
	t_cube	cube;

	init(&cube);
	open_file(str, &cube);
	// print_struct(&cube);
	parsing(&cube);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && checker_file(argv[1]))
		cub3d(argv[1]);
	else
	{
		usage();
		return (1);
	}
	return (0);
}
