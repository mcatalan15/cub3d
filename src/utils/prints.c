/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:13:27 by mcatalan          #+#    #+#             */
/*   Updated: 2024/05/17 12:29:20 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	usage(void)
{
	printf(RED"usage\n"RST);
}

void	print_dp(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
		printf("%s", file[i]);
	printf("\n");
}

void	print_struct(t_cube *cube)
{
	int	i;

	i = -1;
	printf(YLW"FILE\n");
	print_dp(cube->file);
	// printf("MAP\n");
	// print_dp(cube->map);
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
	printf("map_h: %d\n", cube->map_h);
	printf("map_w: %d\n"RST, cube->map_w);
}
