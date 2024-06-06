/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:00:50 by mcatalan@st       #+#    #+#             */
/*   Updated: 2024/06/05 11:12:49 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	free_dp(char **dp)
{
	int	i;

	i = 0;
	while (dp[i])
	{
		free(dp[i]);
		i++;
	}
	free(dp);
	return (0);
}

int	free_all(t_cube *cube)
{
	free_dp(cube->file);
	// free_dp(cube->map);
	free(cube->n_text);
	free(cube->s_text);
	free(cube->e_text);
	free(cube->w_text);
	return (0);
}
