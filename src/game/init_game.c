/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul-kr <jpaul-kr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:44:40 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/04 11:16:53 by jpaul-kr         ###   ########.fr       */
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
	r->map_x = 0;
	r->map_y = 0;
	r->step_x = 0;
	r->step_y = 0;
	r->side = 0;
	r->hit = 0;
}

void	init_texture(void *mlx_ptr, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(mlx_ptr, path, &texture->width,
			&texture->height);
	texture->addr = (int *)mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
}

void	init_textures(t_mlx_data *data)
{
	init_texture(data->mlx, data->n_tex, data->cube->n_text);
	init_texture(data->mlx, data->s_tex, data->cube->s_text);
	init_texture(data->mlx, data->e_tex, data->cube->e_text);
	init_texture(data->mlx, data->w_tex, data->cube->w_text);
}

void	init_player(t_mlx_data *data)
{
	data->p.pos.x = 0;
	data->p.pos.y = 0;
	data->p.old_pos.x = 0;
	data->p.old_pos.y = 0;
	data->p.dir.x = 0;
	data->p.dir.y = 0;
	data->p.plane.x = 0;
	data->p.plane.y = 0;
	data->p.move.x = 0;
	data->p.move.y = 0;
	data->p.angle = 0;
	data->p.old_angle = 0;
	data->p.wasd = 0;
	data->p.map.x = 0;
	data->p.map.y = 0;
	data->p.camerax = 0;
	data->p.sidedist.x = 0;
	data->p.sidedist.y = 0;
	data->p.deltadist.x = 0;
	data->p.deltadist.y = 0;
}

void	init_game(t_mlx_data *data)
{
	data->color = 0;
	init_player(data);
	data->img.ptr = NULL;
	data->img.pixels = NULL;
	data->img.bpp = 0;
	data->img.endian = 0;
	data->img.line_len = 0;
	data->n_tex = malloc(sizeof(t_texture));
	data->s_tex = malloc(sizeof(t_texture));
	data->e_tex = malloc(sizeof(t_texture));
	data->w_tex = malloc(sizeof(t_texture));
}
