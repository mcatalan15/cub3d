/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:05 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/21 19:16:42 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_line(t_mlx_data *data, t_vec st, t_vec end, int color)
{
	t_ray   r;

	r.dx = abs(r.x1 - r.x0);
	r.sx = r.x0 < r.x1 ? 1 : -1;
	r.dy = -abs(r.y1 - r.y0);
	r.sy = r.y0 < r.y1 ? 1 : -1;
	r.err = r.dx + r.dy;
	r.y0 = (int)st.y;
	r.x0 = (int)st.x;
	r.y1 = (int)end.y;
	r.x1 = (int)end.x;
	while (1)
	{
		//printf("x: %d y: %d\n", x0, y0);
		my_pixel_put(&data->img, r.y0, r.x0, color);
		if (r.x0 == r.x1 && r.y0 == r.y1) break;
			r.e2 = 2 * r.err;
		if (r.e2 >= r.dy)
		{
			r.err += r.dy;
			r.x0 += r.sx;
 		}
		if (r.e2 <= r.dx)
		{
			r.err += r.dx;
			r.y0 += r.sy;
		}
	}
}


void	one_ray(t_mlx_data *data, t_cube *cube, t_vec raydir)
{
	t_vec	sidedist;
	t_vec	deltadist;
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

/*
	STEPS:
	1. Calculate the ray's direction
	2. Calculate the distance to the next x or y side
	3. Draw the ray
	4. Draw the rays in FOV (Field of View)
*/
