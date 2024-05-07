/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:32:41 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/07 11:33:21 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init(t_cube *cube)
{
	cube->map = NULL;
	cube->file = NULL;
	cube->n_text = NULL;
	cube->s_text = NULL;
	cube->w_text = NULL;
	cube->e_text = NULL;
	cube->f[0] = -1;
	cube->f[1] = -1;
	cube->f[2] = -1;
	cube->c[0] = -1;
	cube->c[1] = -1;
	cube->c[2] = -1;
	cube->pos = -1;
}