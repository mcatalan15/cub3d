/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:18 by mcatalan          #+#    #+#             */
/*   Updated: 2024/06/17 16:21:20 by jpaul-kr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cube		t_cube;
typedef struct s_mlx_data	t_mlx_data;
typedef struct s_img		t_img;
typedef struct s_vec		t_vec;
typedef struct s_player		t_player;
// typedef struct s_map	t_map;

struct	s_cube
{
	char	**map; //from .cub just the map
	char	**file; //.cub file saved
	char	*n_text; //noth path texture
	char	*s_text; //south path texture
	char	*w_text; //west path texture
	char	*e_text; //east path texture
	int		f[3]; //floor color 0,0,0 -> 255,255,255
	int		c[3]; //ceiling color 0,0,0 -> 255,255,255
	int		pos; //flag start position 1 = N,2 = S,3 = ,4
	int		map_h; //map max height
	int		map_w; //map max width
	int		player_y; //player pos_y
	int		player_x; //player pos_x
};

struct s_img
{
	void	*img;
	char	*pixels;
	int	bytes_per_p;
	int	endian;
	int	line_len;
};

struct s_vec
{
	float	x;
	float	y;
};

struct s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	t_vec	move;
	float	angle;
};

struct	s_mlx_data
{
	void		*mlx;
	void		*win;
	int		color;
	t_player	p;
	t_img		img;
};

#endif
