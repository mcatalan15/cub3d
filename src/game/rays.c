/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:05 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/25 13:25:27 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	draw_line(t_mlx_data *data, t_vec st, t_vec end, int color)
// {
// 	t_ray   r;

// 	r.dx = abs(r.x1 - r.x0);
// 	r.sx = r.x0 < r.x1 ? 1 : -1;
// 	r.dy = -abs(r.y1 - r.y0);
// 	r.sy = r.y0 < r.y1 ? 1 : -1;
// 	r.err = r.dx + r.dy;
// 	r.y0 = (int)st.y;
// 	r.x0 = (int)st.x;
// 	r.y1 = (int)end.y;
// 	r.x1 = (int)end.x;
// 	while (1)
// 	{
// 		//printf("x: %d y: %d\n", x0, y0);
// 		my_pixel_put(&data->img, r.y0, r.x0, color);
// 		if (r.x0 == r.x1 && r.y0 == r.y1) break;
// 			r.e2 = 2 * r.err;
// 		if (r.e2 >= r.dy)
// 		{
// 			r.err += r.dy;
// 			r.x0 += r.sx;
//  		}
// 		if (r.e2 <= r.dx)
// 		{
// 			r.err += r.dx;
// 			r.y0 += r.sy;
// 		}
// 	}
// }

void	one_ray(t_mlx_data *data, t_cube *cube, t_vec raydir)
{
	t_ray	r;

	r.hit = 0;
	r.pos.x = (data->p.pos.x - 100) / BLOCK;
	r.pos.y = (data->p.pos.y - 100) / BLOCK;
	r.mapX = (int)r.pos.x;
	r.mapY = (int)r.pos.y;
	if (!raydir.x)
		r.deltadist.x = 1e30;
	else
		r.deltadist.x = abs((int)(1 / raydir.x));
	if (!raydir.y)
		r.deltadist.y = 1e30;
	else
		r.deltadist.y = abs((int)(1 / raydir.y));
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
	printf("map[%d][%d]\n", r.mapX, r.mapY);
	if (r.side == 0)
		r.prepwalldist = r.sidedist.x - r.deltadist.x;
	else
		r.prepwalldist = r.sidedist.y - r.deltadist.y;
	// printf("sidedistX: %d\tsidedistY: %d\n", (int)r.sidedist.x, (int)r.sidedist.y);
	// printf("deltadistX: %d\tdeltadistY: %d\n", (int)r.deltadist.x, (int)r.deltadist.y);
	double i = (r.mapX * BLOCK) + 100;
	double j = (r.mapY * BLOCK) + 100;
	double raylen = sqrt(i * i + j * j);
	printf("len: %d\n", (int)raylen);
	print_stick(data, raylen, 0xff0000);
}

void	create_rays(t_mlx_data *data, t_cube *cube)
{
	// int		i;
	// double	camerax;
	t_vec	raydir;

	// i = -1;
	data->p.map.x = (data->p.pos.x - 100) / BLOCK;
	data->p.map.y = (data->p.pos.y - 100) / BLOCK;
	raydir.x = data->p.dir.x;
	raydir.y = data->p.dir.y;
	one_ray(data, cube, raydir);
	printf(GREEN"RAYO\n"RST);
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
