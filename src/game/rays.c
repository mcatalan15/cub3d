/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:05 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/26 18:59:35 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_r(t_ray *r)
{
	r->sidedist.x = 0;
	r->sidedist.y = 0;
	r->deltadist.x = 0;
	r->deltadist.y = 0;
	r->pos.x = 0;
	r->pos.y = 0;
	r->prepwalldist = 0;
	r->mapX = 0;
	r->mapY = 0;
	r->stepX = 0;
	r->stepY = 0;
	r->side = 0;
	r->hit = 0;
}

void	one_ray(t_mlx_data *data, t_cube *cube, t_vec raydir, int color)
{
	t_ray	r;
	double mag;

	r.hit = 0;
	r.pos.x = (data->p.pos.x - 100) / BLOCK;
	r.pos.y = (data->p.pos.y - 100) / BLOCK;
	r.mapX = (int)r.pos.x;
	r.mapY = (int)r.pos.y;
	mag = sqrt(raydir.x * raydir.x + raydir.y * raydir.y);
	if (!raydir.x)
		r.deltadist.x = 1e30;
	else
		r.deltadist.x = fabs((mag / raydir.x));
	if (!raydir.y)
		r.deltadist.y = 1e30;
	else
		r.deltadist.y = fabs((mag / raydir.y));
	if (raydir.x < 0)
	{
		r.stepX = -1;
		r.sidedist.x = (r.pos.x - r.mapX) * r.deltadist.x;
	}
	else
	{
		r.stepX = 1;
		r.sidedist.x = (r.mapX + 1.0 - r.pos.x) * r.deltadist.x;
	}
	if (raydir.y < 0)
	{
		r.stepY = -1;
		r.sidedist.y = (r.pos.y - r.mapY) * r.deltadist.y;
	}
	else
	{
		r.stepY = 1;
		r.sidedist.y = (r.mapY + 1.0 - r.pos.y) * r.deltadist.y;
	}
	while (!r.hit)
	{
		if (r.sidedist.x < r.sidedist.y)
		{
			r.sidedist.x += r.deltadist.x;
			r.mapX += r.stepX;
			r.side = 0;
		}
		else
		{
			r.sidedist.y += r.deltadist.y;
			r.mapY += r.stepY;
			r.side = 1;
		}
		if (cube->map[r.mapX][r.mapY] == '1')
			r.hit = 1;
	}
	if (r.side == 0)
		r.prepwalldist = r.sidedist.x - r.deltadist.x;
	else
		r.prepwalldist = r.sidedist.y - r.deltadist.y;
	double raylen = r.prepwalldist * BLOCK;
	print_stick(data, raylen, color);
}


void	create_rays(t_mlx_data *data, t_cube *cube, int color)
{
	// int		i;
	// double	camerax;
	t_vec	raydir;

	// i = -1;
	data->p.map.x = (data->p.pos.x - 100) / BLOCK;
	data->p.map.y = (data->p.pos.y - 100) / BLOCK;
	raydir.x = data->p.dir.x;
	raydir.y = data->p.dir.y;
	one_ray(data, cube, raydir, color);
	/*while (++i < WIDTH)
	{
		camerax = 2 * i / (double)WIDTH - 1;
		raydir.x = data->p.dir.x + data->p.plane.x * camerax;
		raydir.y = data->p.dir.y + data->p.plane.y * camerax;
	}*/
}

/*
	STEPS:
	1. Calculate the ray's direction
	2. Calculate the distance to the next x or y side
	3. Draw the ray
	4. Draw the rays in FOV (Field of View)
*/
