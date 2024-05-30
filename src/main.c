/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:09 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/30 14:20:32 by jpaul-kr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * img->bytes_per_p);
	*((unsigned int *)(img->pixels + offset)) = color;
}

int	print_player(t_mlx_data *data, int x, int y)
{
	int	i;
	int	j;

	i = -5;
	while (++i < 5)
	{
		j = -5;
		while (++j < 5)
			my_pixel_put(&data->img, data->p.pos.y + j, data->p.pos.x + i, 0x000000);
	}
	i = -5;
	while (++i < 5)
	{
		j = -5;
		while (++j < 5)
			my_pixel_put(&data->img, y + j, x + i, data->color);
	}
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y, data->p.dir.x + data->p.pos.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y + data->p.plane.y, data->p.dir.x + data->p.pos.x + data->p.plane.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y - data->p.plane.y, data->p.dir.x + data->p.pos.x - data->p.plane.x, 0x0);
	data->p.pos.x = x;
	data->p.pos.y = y;
	my_pixel_put(&data->img, data->p.dir.y + y, data->p.dir.x + x, data->color);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y + data->p.plane.y, data->p.dir.x + data->p.pos.x + data->p.plane.x, data->color);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y - data->p.plane.y, data->p.dir.x + data->p.pos.x - data->p.plane.x, data->color);
	return (0);
}

int	reset_buttons(int key, t_mlx_data *data)
{
	if (key == 13 || key == 1)
		data->p.uod = 0;
	if (key == 0 || key == 2)
		data->p.lor = 0;
	return (0);
}

void	rotate(t_mlx_data *data, int key)
{
	float		x;
	float		y;
	float	angle;

	//printf("before-> x: %f, y: %f\n", data->p.dir.x, data->p.dir.y);
	angle = PI / 10;
	x = data->p.dir.x;
	y = data->p.dir.y;
	if (key == 124)
		angle *= -1;
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y, data->p.dir.x + data->p.pos.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y + data->p.plane.y, data->p.dir.x + data->p.pos.x + data->p.plane.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y - data->p.plane.y, data->p.dir.x + data->p.pos.x - data->p.plane.x, 0x0);
	data->p.dir.x = (x * cos(angle) - y * sin(angle));
	data->p.dir.y = (x * sin(angle) + y * cos(angle));
	//printf("after-> x: %f, y: %f\n", data->p.dir.x, data->p.dir.y);
	x = data->p.plane.x;
	y = data->p.plane.y;
	data->p.plane.x = (x * cos(angle) - y * sin(angle));
	data->p.plane.y = (x * sin(angle) + y * cos(angle));
}

int	move(int key, t_mlx_data *data)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		data->p.uod = -7;
	if (key == 0)
		data->p.lor = -7;
	if (key == 1)
		data->p.uod = 7;
	if (key == 2)
		data->p.lor = 7;
	if (key == 123 || key == 124)
		rotate(data, key);
	print_player(data, data->p.pos.x + data->p.uod, data->p.pos.y + data->p.lor);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	//printf(" %d \n", key);
	return (0);
}

int	cub3d(char *str)
{
	t_cube	cube;
	t_mlx_data	data;

	(void)str;
	init(&cube);
	data.color = 0x00FF00;
	data.p.pos.x = 500;
	data.p.pos.y = 500;
	data.p.dir.y = 0;
	data.p.dir.x = -40;
	data.p.plane.x = 0;
	data.p.plane.y = 40;
	data.p.uod = 0;
	data.p.lor = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, LENGTH, HEIGHT, "juan");
	data.img.img = mlx_new_image(data.mlx, LENGTH, HEIGHT);
	data.img.pixels = mlx_get_data_addr(data.img.img, \
		&data.img.bytes_per_p, &data.img.line_len, &data.img.endian);
	data.img.bytes_per_p /= 8;
	//print_player(&data, 500, 500);
	//open_file(str, &cube);
	// print_struct(&cube);
	//parsing(&cube);
	//mlx_loop_hook(data.mlx, color_changer, &data);
	//mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_hook(data.win, 3, 1L<<1, reset_buttons, &data);
	mlx_hook(data.win, 2, 1L<<0, move, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	//mlx_destroy_display(data.mlx);
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
