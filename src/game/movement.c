/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul-kr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:37:36 by jpaul-kr          #+#    #+#             */
/*   Updated: 2024/06/17 17:31:42 by jpaul-kr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * img->bytes_per_p);
	*((unsigned int *)(img->pixels + offset)) = color;
}

void	remove_player(t_mlx_data *data)
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
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y, data->p.dir.x + data->p.pos.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y + data->p.plane.y, data->p.dir.x + data->p.pos.x + data->p.plane.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y - data->p.plane.y, data->p.dir.x + data->p.pos.x - data->p.plane.x, 0x0);
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
			my_pixel_put(&data->img, y + j, x + i, data->color);
	}
	data->p.pos.x = x;
	data->p.pos.y = y;
	my_pixel_put(&data->img, data->p.dir.y + y, data->p.dir.x + x, data->color);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y + data->p.plane.y, data->p.dir.x + data->p.pos.x + data->p.plane.x, data->color);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y - data->p.plane.y, data->p.dir.x + data->p.pos.x - data->p.plane.x, data->color);
	return (0);
}

int	reset_buttons(int key, t_mlx_data *data)
{
	if (key == 119 || key == 115 || key == 97 || key == 100)
	{
		data->p.move.x = 0;
		data->p.move.y = 0;
	}
	if (key == 65361 || key == 65363)
		data->p.angle = 0;
	return (0);
}

void	rotate(t_mlx_data *data)
{
	float		x;
	float		y;
	float		angle;

	//printf("before-> x: %f, y: %f\n", data->p.dir.x, data->p.dir.y);
	angle = data->p.angle;
	if (!angle)
		return ;
	x = data->p.dir.x;
	y = data->p.dir.y;
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y, data->p.dir.x + data->p.pos.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y + data->p.plane.y, data->p.dir.x + data->p.pos.x + data->p.plane.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y - data->p.plane.y, data->p.dir.x + data->p.pos.x - data->p.plane.x, 0x0);
	data->p.dir.x = (x * cos(angle) - y * sin(angle));
	data->p.dir.y = (x * sin(angle) + y * cos(angle));
	x = data->p.plane.x;
	y = data->p.plane.y;
	data->p.plane.x = (x * cos(angle) - y * sin(angle));
	data->p.plane.y = (x * sin(angle) + y * cos(angle));

}

int	move(int key, t_mlx_data *data)
{
	if (key == 65307)
		exit(0);
	if (key == 119)
	{
		data->p.move.x = 1;
		data->p.move.y = 1;
	}
	if (key == 97)
	{
		data->p.move.x = 1;
		data->p.move.y = -1;
	}
	if (key == 115)
	{
		data->p.move.x = -1;
		data->p.move.y = -1;
	}
	if (key == 100)
	{
		data->p.move.x = -1;
		data->p.move.y = 1;
	}
	if (key == 65361)
		data->p.angle = PI / 300;
	if (key == 65363)
		data->p.angle = -PI / 300;
	//printf(" %d \n", key);
	return (0);
}

int	my_loop(t_mlx_data *data)
{
	rotate(data);
	remove_player(data);
	data->p.pos.x += (data->p.dir.x / 20) * data->p.move.x;
	data->p.pos.y += (data->p.dir.y / 20) * data->p.move.y;
	print_player(data, data->p.pos.x, data->p.pos.y);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
