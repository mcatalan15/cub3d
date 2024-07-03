/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:57:49 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/03 19:03:08 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_keys_vertical(t_mlx_data *data, double speed, int key)
{
	if (key == W_KEY)
	{
		if (!check_collision(data, 0, data->p.dir.x * speed))
			data->p.pos.x += data->p.dir.x * speed;
		if (!check_collision(data, 1, data->p.dir.y * speed))
			data->p.pos.y += data->p.dir.y * speed;
	}
	if (key == S_KEY)
	{
		if (!check_collision(data, 0, -data->p.dir.x * speed))
			data->p.pos.x -= data->p.dir.x * speed;
		if (!check_collision(data, 1, -data->p.dir.y * speed))
			data->p.pos.y -= data->p.dir.y * speed;
	}
}

void	move_keys_horizontal(t_mlx_data *data, double speed, int key)
{
	if (key == A_KEY)
	{
		if (!check_collision(data, 0, -data->p.dir.y * speed))
			data->p.pos.x -= data->p.dir.y * speed;
		if (!check_collision(data, 1, data->p.dir.x * speed))
			data->p.pos.y += data->p.dir.x * speed;
	}
	if (key == D_KEY)
	{
		if (!check_collision(data, 0, data->p.dir.y * speed))
			data->p.pos.x += data->p.dir.y * speed;
		if (!check_collision(data, 1, -data->p.dir.x * speed))
			data->p.pos.y -= data->p.dir.x * speed;
	}
}

void	rotate_keys(t_mlx_data *data, double angle, int key)
{
	if (key == LEFT_KEY)
	{
		data->p.angle += angle;
		rotate_vector(data, angle);
		normalize_vector(&data->p.dir.x, &data->p.dir.y);
		normalize_vector(&data->p.plane.x, &data->p.plane.y);
	}
	if (key == RIGHT_KEY)
	{
		data->p.angle -= angle;
		rotate_vector(data, -angle);
		normalize_vector(&data->p.dir.x, &data->p.dir.y);
		normalize_vector(&data->p.plane.x, &data->p.plane.y);
	}
}

int	move(int key, t_mlx_data *data)
{
	double	speed;
	double	angle;

	speed = 4;
	angle = 0.1;
	if (key == ESC_KEY)
		exit(0);
	create_rays(data, data->cube);
	rotate_keys(data, angle, key);
	move_keys_vertical(data, speed, key);
	move_keys_horizontal(data, speed, key);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}
