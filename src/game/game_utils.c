/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:33 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/03 18:27:59 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	init_ray_vars(t_ray *r, t_vec raydir)
{
	if (!raydir.y)
		r->deltadist.y = 1e30;
	else
		r->deltadist.y = fabs((1 / raydir.y));
	if (raydir.x < 0)
	{
		r->step_x = -1;
		r->sidedist.x = (r->pos.x - r->map_x) * r->deltadist.x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist.x = (r->map_x + 1.0 - r->pos.x) * r->deltadist.x;
	}
	if (raydir.y < 0)
	{
		r->step_y = -1;
		r->sidedist.y = (r->pos.y - r->map_y) * r->deltadist.y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist.y = (r->map_y + 1.0 - r->pos.y) * r->deltadist.y;
	}
}

void	loop_ray(t_cube *cube, t_ray *r)
{
	while (!r->hit)
	{
		if (r->sidedist.x < r->sidedist.y)
		{
			r->sidedist.x += r->deltadist.x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist.y += r->deltadist.y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (cube->map[r->map_x][r->map_y] == '1')
			r->hit = 1;
	}
	if (r->side == 0)
		r->prepwalldist = r->sidedist.x - r->deltadist.x;
	else
		r->prepwalldist = r->sidedist.y - r->deltadist.y;
}
