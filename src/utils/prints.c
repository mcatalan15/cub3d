/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:13:27 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/07 11:30:42 by mcatalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	usage(void)
{
	printf(RED"usage\n"RST);
}

void	print_struct(t_cube *cube)
{
	int	i;

	i = -1;
	printf("MAP\n");
	// while (cube->map[++i])
	// 	printf("%s\n", cube->map[i]);
	printf("FILE\n");
	i = -1;
	while (cube->file[++i])
		printf("%s", cube->file[i]);
	printf("n_text: %s\n", cube->n_text);
	printf("s_text: %s\n", cube->s_text);
	printf("w_text: %s\n", cube->w_text);
	printf("e_text: %s\n", cube->e_text);
	i = -1;
	while (++i < 3)
		printf("f[%d]: %d\n", i, cube->f[i]);
	i = -1;
	while (++i < 3)
		printf("c[%d]: %d\n", i, cube->c[i]);
	printf("pos: %d\n", cube->pos);
}
