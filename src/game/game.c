/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:58:09 by jpaul-kr          #+#    #+#             */
/*   Updated: 2024/07/03 17:54:25 by mcatalan         ###   ########.fr       */
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
		data->p.dir.x = -1;
		data->p.plane.x = 0;
		data->p.plane.y = -0.66;
	}
	else if (cube->pos == 2)
	{
		data->p.dir.y = 0;
		data->p.dir.x = 1;
		data->p.plane.x = 0;
		data->p.plane.y = 0.66;
	}
	else if (cube->pos == 4)
	{
		data->p.dir.y = 1;
		data->p.dir.x = 0;
		data->p.plane.x = -0.66;
		data->p.plane.y = 0;
	}
	else if (cube->pos == 3)
	{
		data->p.dir.y = -1;
		data->p.dir.x = 0;
		data->p.plane.x = 0.66;
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
		{
			if (!i || i == BLOCK - 1 || !j || j == BLOCK - 1)
				my_pixel_put(&data->img, j + y, i + x, 0xffff00);
			else
				my_pixel_put(&data->img, j + y, i + x, 0xffffff);
		}
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
}

void	path_corrector(t_mlx_data *data)
{
	char	*aux;

	aux = data->cube->n_text;
	data->cube->n_text = ft_strjoin("./", data->cube->n_text);
	free(aux);
	aux = data->cube->s_text;
	data->cube->s_text = ft_strjoin("./", data->cube->s_text);
	free(aux);
	aux = data->cube->e_text;
	data->cube->e_text = ft_strjoin("./", data->cube->e_text);
	free(aux);
	aux = data->cube->w_text;
	data->cube->w_text = ft_strjoin("./", data->cube->w_text);
	free(aux);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	game(t_mlx_data *data, t_cube *cube)
{
	data->cube = cube;
	path_corrector(data);
	init_game(data);
	data->color = 0x00FF00;
	data->p.angle = 0;
	data->mlx = mlx_init();
	init_textures(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->img.ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.pixels = mlx_get_data_addr(data->img.ptr,
			&(data->img.bpp), &(data->img.line_len),
			&(data->img.endian));
	data->img.bpp /= 8;
	add_player(data, cube);
	mlx_hook(data->win, 17, 0, close_window, NULL);
	mlx_hook(data->win, 2, 1L << 0, move, data);
	mlx_loop_hook(data->mlx, my_loop, data);
	mlx_loop(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
}

/*
	STEPS:
	1. Game 2D------------OK
		1.1 Print map---------------------------------OK
		1.2 Print player------------------------------OK
		1.3 Player movements--------------------------OK
			1.3.1 Rotate player---------------------------------OK
			1.3.2 Move player (with direction)------------------OK
			1.3.3 Map colision----------------------------------Ok
		1.4 Move player (with direction)--------------OK
		1.5 Print Rays (FOV)--------------------------OK
			1.5.1 Print one ray---------------------------------OK
			1.5.2 Print ray with vertical colision--------------OK
			1.5.3 Print ray with horizontal coliision-----------OK
			1.5.4 Print rays in FOV-----------------------------OK
	2. Game 3D------------
		2.1 Raycasting--------------------------------
		2.2 Print 3D walls----------------------------
		2.3 Print floor & ceiling---------------------
		2.4 Print sprites & textures------------------
	3. Correct & test-----
		3.1 Correct leaks-----------------------------
		3.2 Test Norminette---------------------------
		3.3 Change textures---------------------------
		3.4 Change sprites----------------------------
*/
