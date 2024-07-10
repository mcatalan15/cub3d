/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:05 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/10 11:02:58 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	one_ray(t_mlx_data *data, t_cube *cube, t_vec raydir, t_ray *r)
{
	r->hit = 0;
	r->pos.x = (data->p.pos.x - 100) / BLOCK;
	r->pos.y = (data->p.pos.y - 100) / BLOCK;
	r->map_x = (int)r->pos.x;
	r->map_y = (int)r->pos.y;
	if (!raydir.x)
		r->deltadist.x = 1e30;
	else
		r->deltadist.x = fabs((1 / raydir.x));
	init_ray_vars(r, raydir);
	loop_ray(cube, r);
}

void	create_wall(t_mlx_data *data, t_ray *r, t_vec raydir, t_draw d)
{
	r->tex_y = ((r->d_y * data->n_tex->height) / d.line_height) / 256;
	if (r->tex_x < 0 || r->tex_y < 0 || r->tex_x > 64 || r->tex_y > 64)
		r->color = 0;
	else
	{
		if (r->side == 1)
		{
			if (raydir.y > 0)
				r->color = data->w_tex->addr[r->tex_y
					* data->w_tex->line_len / 4 + r->tex_x];
			else
				r->color = data->e_tex->addr[r->tex_y
					* data->e_tex->line_len / 4 + r->tex_x];
		}
		else
		{
			if (raydir.x > 0)
				r->color = data->n_tex->addr[r->tex_y
					* data->n_tex->line_len / 4 + r->tex_x];
			else
				r->color = data->s_tex->addr[r->tex_y
					* data->s_tex->line_len / 4 + r->tex_x];
		}
	}
}

void	wall_maths(t_mlx_data *data, t_draw *d, t_ray *r, t_vec raydir)
{
	double	wall_x;

	d->line_height = (int)(HEIGHT / r->prepwalldist);
	d->aux_start = -d->line_height / 2 + HEIGHT / 2;
	d->aux_end = d->line_height / 2 + HEIGHT / 2;
	if (d->aux_start < 0)
		d->draw_start = 0;
	else
		d->draw_start = d->aux_start;
	if (d->aux_end >= HEIGHT)
		d->draw_end = HEIGHT - 1;
	else
		d->draw_end = d->aux_end;
	if (r->side == 0)
		wall_x = r->pos.y + r->prepwalldist * raydir.y;
	else
		wall_x = r->pos.x + r->prepwalldist * raydir.x;
	wall_x -= floor((wall_x));
	r->tex_x = (int)(wall_x * (double)(data->n_tex->width));
	if (r->side == 0 && raydir.x > 0)
		r->tex_x = data->n_tex->width - r->tex_x - 1;
	if (r->side == 1 && raydir.y < 0)
		r->tex_x = data->n_tex->width - r->tex_x - 1;
}

void	wall(t_mlx_data *data, t_ray *r, t_vec raydir, int i)
{
	t_draw	d;
	int		j;

	wall_maths(data, &d, r, raydir);
	j = -1;
	while (++j < HEIGHT)
	{
		if (j < d.draw_start)
			my_pixel_put(&data->img, i, j,
				data->cube->c[0] << 16 | data->cube->c[1] << 8
				| data->cube->c[2]);
		else if (j >= d.draw_start && j <= d.draw_end)
		{
			r->d_y = j * 256 - HEIGHT * 128 + d.line_height * 128;
			create_wall(data, r, raydir, d);
			my_pixel_put(&data->img, i, j, r->color);
		}
		else
			my_pixel_put(&data->img, i, j, data->cube->f[0] << 16
				| data->cube->f[1] << 8 | data->cube->f[2]);
	}
}

void	create_rays(t_mlx_data *data, t_cube *cube)
{
	int		i;
	double	camerax;
	t_vec	raydir;
	t_ray	r;

	i = -1;
	data->p.map.x = (data->p.pos.x - 100) / BLOCK;
	data->p.map.y = (data->p.pos.y - 100) / BLOCK;
	raydir.x = data->p.dir.x;
	raydir.y = data->p.dir.y;
	while (++i < WIDTH)
	{
		camerax = -(2 * i / (double)WIDTH - 1);
		raydir.x = data->p.dir.x + data->p.plane.x * camerax;
		raydir.y = data->p.dir.y + data->p.plane.y * camerax;
		one_ray(data, cube, raydir, &r);
		wall(data, &r, raydir, i);
	}
}

/*
	STEPS:
	1. Calculate the ray's direction-----------------------OK
	2. Calculate the distance to the next x or y side------OK
	3. Draw the ray----------------------------------------OK
	4. Draw the rays in FOV (Field of View)----------------OK
*/

/*
2. Game 3D------------
		2.1 Print 3D walls----------------------------OK
		2.2 Print floor & ceiling---------------------OK
		2.3 Print without fish eye effect-------------
		2.3 Print sprites & textures------------------
*/
