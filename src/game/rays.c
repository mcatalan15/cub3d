/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:34:05 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/03 12:28:45 by mcatalan         ###   ########.fr       */
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

void	one_ray(t_mlx_data *data, t_cube *cube, t_vec raydir, t_ray *r)
{
	// double	mag;
	// t_vec	sum;

	r->hit = 0;
	r->pos.x = (data->p.pos.x - 100) / BLOCK;
	r->pos.y = (data->p.pos.y - 100) / BLOCK;
	r->mapX = (int)r->pos.x;
	r->mapY = (int)r->pos.y;
	// sum.x = 0;
	// sum.y = 0;
	// mag = sqrt(raydir.x * raydir.x + raydir.y * raydir.y);
	if (!raydir.x)
		r->deltadist.x = 1e30;
	else
		r->deltadist.x = fabs((1 / raydir.x));
	if (!raydir.y)
		r->deltadist.y = 1e30;
	else
		r->deltadist.y = fabs((1 / raydir.y));
	if (raydir.x < 0)
	{
		r->stepX = -1;
		r->sidedist.x = (r->pos.x - r->mapX) * r->deltadist.x;
		// sum.x = r->pos.x - r->mapX;
	}
	else
	{
		r->stepX = 1;
		r->sidedist.x = (r->mapX + 1.0 - r->pos.x) * r->deltadist.x;
		// sum.x = r->mapX + 1.0 - r->pos.x;
	}
	if (raydir.y < 0)
	{
		r->stepY = -1;
		r->sidedist.y = (r->pos.y - r->mapY) * r->deltadist.y;
		// sum.y = r->pos.y - r->mapY;
	}
	else
	{
		r->stepY = 1;
		r->sidedist.y = (r->mapY + 1.0 - r->pos.y) * r->deltadist.y;
		// sum.y = r->mapY + 1.0 - r->pos.y;
	}
	while (!r->hit)
	{
		if (r->sidedist.x < r->sidedist.y)
		{
			r->sidedist.x += r->deltadist.x;
			r->mapX += r->stepX;
			// sum.x += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sidedist.y += r->deltadist.y;
			r->mapY += r->stepY;
			// sum.y += r->stepY;
			r->side = 1;
		}
		if (cube->map[r->mapX][r->mapY] == '1')
			r->hit = 1;
	}
	if (r->side == 0)
	{
		r->prepwalldist = r->sidedist.x - r->deltadist.x;
		// r->pos.x += sum.x - r->stepX;
		// r->pos.y += sqrt(r->prepwalldist * r->prepwalldist - sum.x * sum.x) * r->stepY;
	}
	else
	{
		r->prepwalldist = r->sidedist.y - r->deltadist.y;
		// r->pos.y += sum.y - r->stepY;
		// r->pos.x += sqrt(r->prepwalldist * r->prepwalldist - sum.y * sum.y) * r->stepX;
	}
	// r->raylen = r->prepwalldist * BLOCK;
	// print_stick(data, raydir, raylen, color);
}

// void create_rays(t_mlx_data *data, t_cube *cube, int color)
// {
//     int i = 0;
//     double camerax;
//     t_vec raydir;

//     while (i < WIDTH)
//     {
//         camerax = 2 * i / (double)WIDTH - 1; // Normaliza el índice del rayo
//         raydir.x = data->p.dir->x + data->p.plane.x * camerax;
//         raydir.y = data->p.dir->y + data->p.plane.y * camerax;
//         one_ray(data, cube, raydir, color);
//         i++;
//     }
// }

// int	calculate_color(t_texture *texture, t_ray *r, int j, t_draw d)
// {
// 	int	y;
// 	int	x;
// 	int	color;

// 	if (r->side)
// 		x = texture->width * (r->pos.x- (int)r->pos.x);
// 	else
// 		x = texture->width * (r->pos.y - (int) r->pos.y);
// 	y = texture->height * ((float)(j - d.drawStart - (d.auxStart - d.drawStart)) / (d.auxEnd - d.auxStart));
// 	color = (*(int *)(texture->addr + y * texture->line_len + x * (texture->bpp / 8)));
// 	return (color);
// }

// int	get_color(t_texture *tex, t_ray *r, t_draw d, t_vec raydir, int	texY)
// {
// 	if (texY >= tex->height)
// 		texY -= tex->height;
// 	d.texX = (int)(d.wallX * (double)tex->width);
// 	if (r->side == 0 && raydir.x > 0)
// 		d.texX = tex->width - d.texX - 1;
// 	if (r->side == 1 && raydir.y < 0)
// 		d.texX = tex->width - d.texX - 1;
// 	double step = 1.0 * tex->height / d.lineHeight;
// 	d.texPos = (d.drawStart - HEIGHT / 2 + d.lineHeight / 2) * step;
// 	// int texY = (int)d.texPos & (tex->height - 1);
// 	d.texPos += step;
// 	printf("height: %d, texX: %d, texY: %d\n",tex->height, d.texX, texY);
// 	int	color = tex->addr[tex->height * texY + d.texX];
// 	return (color);
// }

void	wall(t_mlx_data *data, t_ray *r, t_vec raydir, int i)
{
	t_draw	d;
	// double	mag;

	// mag = sqrt(raydir.x * raydir.x + raydir.y * raydir.y);
	d.lineHeight = (int)(HEIGHT / r->prepwalldist);
	d.auxStart = -d.lineHeight / 2 + HEIGHT / 2;
	d.auxEnd = d.lineHeight / 2 + HEIGHT / 2;

	if (d.auxStart < 0)
		d.drawStart = 0;
	else
		d.drawStart = d.auxStart;
	if (d.auxEnd >= HEIGHT)
		d.drawEnd = HEIGHT - 1;
	else
		d.drawEnd = d.auxEnd;

    // Coordenadas de la textura
	double	wallX;
	if (r->side == 0) // E-W
		wallX = data->p.pos.y + r->prepwalldist * raydir.y;
    else // N-S
		wallX = data->p.pos.x + r->prepwalldist * raydir.x;
	wallX -= floor((wallX));

    // Coordenada X en la textura
	int texX = (int)(wallX * (double)(data->n_tex->width));
	if (r->side == 0 && raydir.x > 0)
		texX = data->n_tex->width - texX - 1;
	if (r->side == 1 && raydir.y < 0)
		texX = data->n_tex->width - texX - 1;

	int j = -1;
	while (++j < HEIGHT)
	// while (++j < 1)
	{
		if (j < d.drawStart)
			my_pixel_put(&data->img, i, j, data->cube->f[0] << 16 | data->cube->f[1] << 8 | data->cube->f[2]);
		else if (j >= d.drawStart && j <= d.drawEnd)
		{
			// /////
			// d.lineHeight = (int)(HEIGHT / r->prepwalldist);
			// d.auxStart = -d.lineHeight / 2 + HEIGHT / 2;
			// d.auxEnd = d.lineHeight / 2 + HEIGHT / 2;

			// if (d.auxStart < 0)
			// 	d.drawStart = 0;
			// else
			// 	d.drawStart = d.auxStart;
			// if (d.auxEnd >= HEIGHT)
			// 	d.drawEnd = HEIGHT - 1;
			// else
			// 	d.drawEnd = d.auxEnd;

			// // Coordenadas de la textura
			// double	wallX;
			// if (r->side == 0) // E-W
			// 	wallX = data->p.pos.y + r->prepwalldist * raydir.y;
			// else // N-S
			// 	wallX = data->p.pos.x + r->prepwalldist * raydir.x;
			// wallX -= floor((wallX));

			// // Coordenada X en la textura
			// int texX = (int)(wallX * (double)(data->n_tex->width));
			// if (r->side == 0 && raydir.x > 0)
			// 	texX = data->n_tex->width - texX - 1;
			// if (r->side == 1 && raydir.y < 0)
			// 	texX = data->n_tex->width - texX - 1;
			// /////
			int d_y = j * 256 - HEIGHT * 128 + d.lineHeight * 128;
			int texY = ((d_y * data->n_tex->height) / d.lineHeight) / 256;
			int color;
			if (r->side == 0)
			{
				if (raydir.x > 0) // E
					color = data->e_tex->addr[texY * data->e_tex->line_len / 4 + texX];
				else // W
					color = data->w_tex->addr[texY * data->w_tex->line_len / 4 + texX];
			}
			else
			{
                if (raydir.y > 0) // N
					color = data->n_tex->addr[texY * data->n_tex->line_len / 4 + texX];
                else // S
					color = data->s_tex->addr[texY * data->s_tex->line_len / 4 + texX];
			}
			// printf("color: %d\n", color);
			// printf("texY: %d\n", texY);
			// printf("texX: %d\n", texX);
			my_pixel_put(&data->img, i, j, color);
		}
		else
			my_pixel_put(&data->img, i, j, data->cube->c[0] << 16 | data->cube->c[1] << 8 | data->cube->c[2]);
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
		// int lineHeight = (int)(HEIGHT / r.prepwalldist);
		// printf("lineHeight: %d\n", lineHeight);
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
