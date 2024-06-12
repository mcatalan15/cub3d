/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul-kr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:58:09 by jpaul-kr          #+#    #+#             */
/*   Updated: 2024/06/12 13:10:08 by jpaul-kr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    print_block(t_mlx_data *data, int x, int y)
{
        int     i;
        int     j;

        i = -1;
        while (++i < 10)
        {
                j = -1;
                while (++j < 10)
                        my_pixel_put(data->img.img, x + i, y + j, 0xffffff);
        }
}

void    print_map(t_cube *cube, t_mlx_data *data)
{
        int     x;
        int     y;
        int     i;
        int     j;

        x = 100;
        y = 100;
        i = -1;
        while (++i < cube->map_h)
        {
                j = -1;
                while (++j < cube->map_w)
                {
                        if (cube->map[i][j] == '1')
                                print_block(data, x, y);
                        y += 10;
                }
                x += 10;
        }
}

void	game(t_mlx_data *data)
{
	data->color = 0x00FF00;
        data->p.pos.x = 500;
        data->p.pos.y = 500;
        data->p.dir.y = 0;
        data->p.dir.x = -40;
        data->p.plane.x = 0;
        data->p.plane.y = 40;
        data->p.uod = 0;
        data->p.lor = 0;
        dat->p.angle = 0;
        data->mlx = mlx_init();
        data->win = mlx_new_window(data->mlx, LENGTH, HEIGHT, "juan");
        data->img.img = mlx_new_image(data->mlx, LENGTH, HEIGHT);
        data->img.pixels = mlx_get_data_addr(data->img.img, \
                data->img.bytes_per_p, data->img.line_len, data->img.endian);
        data->img.bytes_per_p /= 8;
        mlx_hook(data->win, 3, 1L<<1, reset_buttons, data);
        mlx_hook(data->win, 2, 1L<<0, move, data);
        mlx_loop_hook(data->mlx, my_loop, data);
        mlx_loop(data->mlx);
        mlx_destroy_window(data->mlx, data->win);
        free(data->mlx);
}

