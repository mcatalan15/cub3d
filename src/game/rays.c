/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:05 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/20 11:53:03 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	one_ray(t_mlx_data *data, t_cube *cube, t_vec raydir)
{
	float	atan;
	double	ra;
	int		r;
	int		yo; //deltaDistY
	int		xo; //deltaDistX
	ra = data->p.angle;
	r = 0;
	//sideDistX
	
	//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX)) 
	
	while (r < 1)
	{
		//Check horizontal lines
		atan = -1/tan(data->p.angle);
		if (ra > M_PI) //looking up
		{
			raydir.y = (((int)data->p.pos.x>>6)<<6) - 0.0001;
			raydir.x = (data->p.pos.x-raydir.y) * atan + data->p.pos.x;
			yo = -BLOCK;
			xo = -yo * atan;
		}
		//looking down
		if (ra < M_PI)
		{
			raydir.y = (((int)data->p.pos.x>>6)<<6) + BLOCK;
			raydir.x = (data->p.pos.y - raydir.y) * atan + data->p.pos.x;
			yo = BLOCK;
			xo = -yo * atan;
		}
		// looking straight left or right
		if (ra == 0 || ra == M_PI)
		{
			raydir.x = data->p.pos.x;
			raydir.y = data->p.pos.y;
		}
		r++;
	}
}

void	create_rays(t_mlx_data *data, t_cube *cube)
{
	int		i;
	double	camerax;
	t_vec	raydir;

	i = -1;
	data->p.map.x = (data->p.pos.x - 100) / BLOCK;
	data->p.map.y = (data->p.pos.y - 100) / BLOCK;
	raydir.x = data->p.dir.x;
	raydir.y = data->p.dir.y;
	one_ray(data, cube, raydir);
	/*while (++i < WIDTH)
	{
		camerax = 2 * i / (double)WIDTH - 1;
		raydir.x = data->p.dir.x + data->p.plane.x * camerax;
		raydir.y = data->p.dir.y + data->p.plane.y * camerax;
	}*/
}
