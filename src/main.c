/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/05 11:07:13 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub3d(char *str)
{
	t_cube	cube;

	if (checker_map_extension(str))
	{
		printf(RED"ERROR:\n\tMap not valid. must be .cub\n"RST);
		exit(1);
	}
	init(&cube);
	open_file(str, &cube);
	parsing(&cube);
	free_all(&cube);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		cub3d(argv[1]);
	else
	{
		usage();
		return (1);
	}
	return (0);
}
