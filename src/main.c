/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/12 13:03:41 by jpaul-kr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	cub3d(char *str)
{
	t_cube		cube;
	t_mlx_data	data;

	if (checker_map_extension(str))
	{
		printf(RED"ERROR:\n\tMap not valid. must be .cub\n"RST);
		exit(1);
	}
	init(&cube);
	open_file(str, &cube);
	parsing(&cube);
	game(&data);
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
