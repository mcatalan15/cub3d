/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:37:18 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/06 13:09:46 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cube	t_cube;
// typedef struct s_map	t_map;

// struct s_map
// {
// 	char **map;
//
// };

struct	s_cube
{
	char	**map;
	char	**file;
	char	*n_text;
	char	*s_text;
	char	*w_text;
	char	*e_text;
	int		*f;
	int		*c;
	int		n;
};

#endif