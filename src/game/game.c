/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:18:13 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/13 18:32:43 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void game(t_mlx_data *data, t_cube *cube)
{
    (void)cube;
    data->color = 0x00FF00;
    data->p.pos.x = 500;
    data->p.pos.y = 500;
    data->p.dir.y = 0;
    data->p.dir.x = -40;
    data->p.plane.x = 0;
    data->p.plane.y = 40;
    data->p.uod = 0;
    data->p.lor = 0;
    data->p.angle = 0;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, LENGTH, HEIGHT, "juan");
    data->img.img = mlx_new_image(data->mlx, LENGTH, HEIGHT);
    data->img.pixels = mlx_get_data_addr(data->img.img,
        &(data->img.bytes_per_p), &(data->img.line_len), &(data->img.endian));
    data->img.bytes_per_p /= 8;
    mlx_hook(data->win, 3, 1L<<1, reset_buttons, data);
    mlx_hook(data->win, 2, 1L<<0, move, data);
    mlx_loop_hook(data->mlx, my_loop, data);
    mlx_loop(data->mlx);
    mlx_destroy_window(data->mlx, data->win);
    free(data->mlx);
}
