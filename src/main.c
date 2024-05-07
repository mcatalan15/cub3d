/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/07 12:28:55 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (argc == 2)
		cub3d(argv[1]);
	else
	{
		usage();
		return (1);
	}
	return (0);
}
