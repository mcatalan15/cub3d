/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/10 13:20:10 by jpaul-kr         ###   ########.fr       */
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
	free_all(&cube);
	data.color = 0x00FF00;
	data.p.pos.x = 500;
	data.p.pos.y = 500;
	data.p.dir.y = 0;
	data.p.dir.x = -40;
	data.p.plane.x = 0;
	data.p.plane.y = 40;
	data.p.uod = 0;
	data.p.lor = 0;
	data.p.angle = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, LENGTH, HEIGHT, "juan");
	data.img.img = mlx_new_image(data.mlx, LENGTH, HEIGHT);
	data.img.pixels = mlx_get_data_addr(data.img.img, \
		&data.img.bytes_per_p, &data.img.line_len, &data.img.endian);
	data.img.bytes_per_p /= 8;
	mlx_hook(data.win, 3, 1L<<1, reset_buttons, &data);
	mlx_hook(data.win, 2, 1L<<0, move, &data);
	mlx_loop_hook(data.mlx, my_loop, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	free(data.mlx);
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
