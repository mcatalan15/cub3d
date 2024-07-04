/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul-kr <jpaul-kr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:18 by mcatalan          #+#    #+#             */
/*   Updated: 2024/07/04 12:34:28 by jpaul-kr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cube		t_cube;
typedef struct s_mlx_data	t_mlx_data;
typedef struct s_img		t_img;
typedef struct s_vec		t_vec;
typedef struct s_veci		t_veci;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_texture	t_texture;
typedef struct s_draw		t_draw;

struct	s_cube
{
	char	**map;
	char	**file;
	char	*n_text;
	char	*s_text;
	char	*w_text;
	char	*e_text;
	int		f[3];
	int		c[3];
	int		pos;
	int		map_h;
	int		map_w;
	int		player_y;
	int		player_x;
};

struct s_img
{
	void	*ptr;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
};

struct s_vec
{
	double	x;
	double	y;
};

struct s_veci
{
	int	x;
	int	y;
};

struct s_player
{
	t_vec	pos;
	t_vec	old_pos;
	t_vec	dir;
	t_vec	plane;
	t_vec	move;
	double	angle;
	double	old_angle;
	int		wasd;
	t_vec	map;
	double	camerax;
	t_vec	sidedist;
	t_vec	deltadist;
};

struct	s_mlx_data
{
	void		*mlx;
	void		*win;
	int			color;
	t_player	p;
	t_img		img;
	t_cube		*cube;
	t_texture	*n_tex;
	t_texture	*s_tex;
	t_texture	*e_tex;
	t_texture	*w_tex;
	// t_ray		*r;
};

struct s_ray
{
	t_vec	sidedist;
	t_vec	deltadist;
	t_vec	pos;
	double	prepwalldist;
	double	raylen;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	int		tex_x;
	int		d_y;
	int		tex_y;
	int		color;
};

struct s_texture
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
};

struct s_draw
{
	int		draw_start;
	int		draw_end;
	int		aux_start;
	int		aux_end;
	int		line_height;
	int		tex_x;
	int		wall_x;
};

#endif
