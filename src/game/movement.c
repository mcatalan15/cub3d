/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:37:36 by jpaul-kr          #+#    #+#             */
/*   Updated: 2024/06/19 15:48:04 by mcatalan         ###   ########.fr       */
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
		// printf("posx: %d, posy: %d\n", (int)data->p.pos.x, (int)data->p.pos.y);
		while (++j < 5)
			my_pixel_put(&data->img, data->p.old_pos.y + j, data->p.old_pos.x + i,  0x000000);
	}
	my_pixel_put(&data->img, data->p.dir.y + data->p.old_pos.y, data->p.dir.x + data->p.old_pos.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.old_pos.y + data->p.plane.y, data->p.dir.x + data->p.old_pos.x + data->p.plane.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.old_pos.y - data->p.plane.y, data->p.dir.x + data->p.old_pos.x - data->p.plane.x, 0x0);
	data->p.old_pos.x = data->p.pos.x;
	data->p.old_pos.y = data->p.pos.y;
}
// tratar de cambiar la x,y de lado a ver si funciona
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
		data->p.wasd = 0;
	if (key == 65361 || key == 65363)
		data->p.angle = 0;
	return (0);
}

void	normalize_vector(double *x, double *y)
{
	double	magnitude = sqrt((*x) * (*x) + (*y) * (*y));
	if (!magnitude)
	{
		*x /= magnitude;
		*y /= magnitude;
	}
}

void	rotate(t_mlx_data *data)
{
	double		x;
	double		y;
	double		angle;

	//printf("before-> x: %f, y: %f\n", data->p.dir.x, data->p.dir.y);
	if (data->p.angle > 2 * M_PI)
		data->p.angle -= 2 * M_PI;
	if (data->p.angle < -2 * M_PI)
		data->p.angle += 2 * M_PI;
	angle = data->p.angle;	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y, data->p.dir.x + data->p.pos.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y + data->p.plane.y, data->p.dir.x + data->p.pos.x + data->p.plane.x, 0x0);
	my_pixel_put(&data->img, data->p.dir.y + data->p.pos.y - data->p.plane.y, data->p.dir.x + data->p.pos.x - data->p.plane.x, 0x0);
	x = data->p.dir.x;
	y = data->p.dir.y;
	data->p.dir.x = (x * cos(angle) - y * sin(angle));
	data->p.dir.y = (x * sin(angle) + y * cos(angle));
	x = data->p.plane.x;
	y = data->p.plane.y;
	data->p.plane.x = (x * cos(angle) - y * sin(angle));
	data->p.plane.y = (x * sin(angle) + y * cos(angle));
	data->p.move.x = data->p.dir.x / 20;
	data->p.move.y = data->p.dir.y / 20;
}

void	rotate_vector(double *x, double *y, double theta)
{
	float	cos_theta = cos(theta);
	float	sin_theta = sin(theta);
 	float	new_x;
	float	new_y;

	new_x = *x * cos_theta - *y * sin_theta;
	new_y = *x * sin_theta + *y * cos_theta;
	*x = new_x;
	*y = new_y;
}

int	move(int key, t_mlx_data *data)
{
	if (key == ESC_KEY)
		exit(0);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		data->p.wasd = 1;
	if (key == W_KEY)
		data->p.angle_dir = 0;
	if (key == A_KEY)
		data->p.angle_dir = M_PI / 2;
	if (key == S_KEY)
		data->p.angle_dir = M_PI;
	if (key == D_KEY)
		data->p.angle_dir = -M_PI / 2;
	if (key == LEFT_KEY)
		data->p.angle += M_PI / 300;
	if (key == RIGHT_KEY)
		data->p.angle -= M_PI / 300;
	// int	pdx;
	// int	pdy;

	// if (key == LEFT_KEY)
	// {
	// 	data->p.angle -= 0.1;
	// 	if (data->p.angle < 0)
	// 		data->p.angle += 2 * M_PI;
	// 	pdx = cos(data->p.angle) / 10;
	// 	pdy = sin(data->p.angle) / 10;
	// }
	// if (key == RIGHT_KEY)
	// {
	// 	data->p.angle += 0.1;
	// 	if (data->p.angle > 2 * M_PI)
	// 		data->p.angle -= 2 * M_PI;
	// 	pdx = cos(data->p.angle) / 10;
	// 	pdy = sin(data->p.angle) / 10;
	// }
	// if (key == A_KEY)
	// {
	// 	data->p.pos.x -= pdx / 10000;
	// 	data->p.pos.y += pdy / 10000;
	// }
	// if (key == D_KEY)
	// {
	// 	data->p.pos.x += pdx / 10000;
	// 	data->p.pos.y -= pdy / 10000;
	// }
	// if (key == W_KEY)
	// {
	// 	data->p.pos.x += pdx / 10000;
	// 	data->p.pos.y += pdy / 10000;
	// }
	// if (key == S_KEY)
	// {
	// 	data->p.pos.x -= pdx / 10000;
	// 	data->p.pos.y -= pdy / 10000;
	// }
	return (0);
}

int	my_loop(t_mlx_data *data)
{
	rotate(data);
	printf("posx: %d  posy: %d\n", (int)data->p.pos.x, (int)data->p.pos.y);
	remove_player(data);
	rotate_vector(&data->p.move.x, &data->p.move.y, data->p.angle_dir);
	normalize_vector(&data->p.move.x, &data->p.move.y);
	data->p.pos.x += data->p.move.x * data->p.wasd;
	data->p.pos.y += data->p.move.y * data->p.wasd;
	print_player(data, data->p.pos.x, data->p.pos.y);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
