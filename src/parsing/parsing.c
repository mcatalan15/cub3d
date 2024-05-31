/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:34:26 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/31 11:36:21 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parsing(t_cube *cube)
{
	int	pos_map;

	pos_map = get_info(cube);
	checker_vals(cube);
	print_struct(cube);
	(void)pos_map;
	// map_parsing(cube, pos_map);
	return (0);
}
