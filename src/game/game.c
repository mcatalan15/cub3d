/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:58:09 by jpaul-kr          #+#    #+#             */
/*   Updated: 2024/06/19 15:38:02 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_player(t_mlx_data *data, t_cube *cube)
{
	data->p.pos.x = (cube->player_x * BLOCK + 100) + BLOCK / 2;
	data->p.pos.y = (cube->player_y * BLOCK + 100) + BLOCK / 2;
	data->p.old_pos.x = data->p.pos.x;
	data->p.old_pos.y = data->p.pos.y;
	if (cube->pos == 1)
	{
		data->p.dir.y = 0;
		data->p.dir.x = -40;
		data->p.plane.x = 0;
		data->p.plane.y = 40;
	}
	else if (cube->pos == 2)
	{
		data->p.dir.y = 0;
		data->p.dir.x = 40;
		data->p.plane.x = 0;
		data->p.plane.y = -40;
	}
	else if (cube->pos == 4)
	{
		data->p.dir.y = 40;
		data->p.dir.x = 0;
		data->p.plane.x = -40;
		data->p.plane.y = 0;
	}
	else if (cube->pos == 3)
	{
		data->p.dir.y = -40;
		data->p.dir.x = 0;
		data->p.plane.x = 40;
		data->p.plane.y = 0;
	}
}

void	print_block(t_mlx_data *data, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < BLOCK)
	{
		j = -1;
		while (++j < BLOCK)
			my_pixel_put(&data->img, j + y, i + x, 0xffffff);
	}
}

void	print_map(t_mlx_data *data, t_cube *cube)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 100;
	i = -1;
	while (++i < cube->map_h)
	{
		j = -1;
		y = 100;
		while (++j < cube->map_w)
		{
			if (cube->map[i][j] == '1')
				print_block(data, x, y);
			add_player(data, cube);
			y += BLOCK;
		}
		x += BLOCK;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	game(t_mlx_data *data, t_cube *cube)
{
	data->color = 0x00FF00;
	data->p.move.x = 0;
	data->p.move.y = 0;
	data->p.wasd = 0;
	data->p.angle = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.pixels = mlx_get_data_addr(data->img.img,
			&(data->img.bytes_per_p), &(data->img.line_len),
			&(data->img.endian));
	data->img.bytes_per_p /= 8;
	print_map(data, cube);
	//printf("posx: %d  posy: %d\n", (int)data->p.pos.x, (int)data->p.pos.y);
	mlx_hook(data->win, 3, 1L<<1, reset_buttons, data);
	mlx_hook(data->win, 2, 1L<<0, move, data);
	mlx_loop_hook(data->mlx, my_loop, data);
	mlx_loop(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
}
