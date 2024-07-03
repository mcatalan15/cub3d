/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:16:37 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/03 19:03:01 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * img->bpp);
	*((unsigned int *)(img->pixels + offset)) = color;
}

void	normalize_vector(double *x, double *y)
{
	double	magnitude;

	magnitude = sqrt((*x) * (*x) + (*y) * (*y));
	if (!magnitude)
	{
		*x /= magnitude;
		*y /= magnitude;
	}
}

void	rotate_vector(t_mlx_data *data, double theta)
{
	float	cos_theta;
	float	sin_theta;
	float	new_x;
	float	new_y;

	sin_theta = sin(theta);
	cos_theta = cos(theta);
	new_x = data->p.dir.x * cos_theta - data->p.dir.y * sin_theta;
	new_y = data->p.dir.x * sin_theta + data->p.dir.y * cos_theta;
	data->p.dir.x = new_x;
	data->p.dir.y = new_y;
	new_x = data->p.plane.x * cos_theta - data->p.plane.y * sin_theta;
	new_y = data->p.plane.x * sin_theta + data->p.plane.y * cos_theta;
	data->p.plane.x = new_x;
	data->p.plane.y = new_y;
}

bool	check_collision(t_mlx_data *data, int flag, double sum)
{
	double	y;
	double	x;

	x = data->p.pos.x;
	y = data->p.pos.y;
	if (!flag)
		x += sum;
	else
		y += sum;
	x = (x - 100) / BLOCK;
	y = (y - 100) / BLOCK;
	if (data->cube->map[(int)x][(int)y] == '1')
		return (true);
	return (false);
}

// int	reset_buttons(int key, t_mlx_data *data)
// {
// 	if (key == 119 || key == 115 || key == 97 || key == 100)
// 		data->p.wasd = 0;
// 	if (key == 65361 || key == 65363)
// 		data->p.angle = 0;
// 	return (0);
// }

int	my_loop(t_mlx_data *data)
{
	create_rays(data, data->cube);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
	return (0);
}

/*
	NECESITAMOS
	-Printear player donde corresponde del mapa -------------OK
	-Que se mueva la direccion (personaje con punto)---------OK
		-Poner punto-----------------------------------------OK
		-Mover punto con direccion---------------------------OK
	-Mover a la direccion de la posicion.--------------------OK
	-Normalizar posicion-------------------------------------OK
	-Colisiones----------------------------------------------OK
*/
